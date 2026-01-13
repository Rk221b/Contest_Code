#include <bits/stdc++.h>
using namespace std;

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    ofstream file;
    mutex mtx;

    // Private constructor
    Logger() {
        file.open("app.log", ios::app);
        if (!file.is_open()) {
            throw runtime_error("Failed to open log file");
        }
    }

    // Delete copy operations
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    string levelToString(LogLevel level) {
        switch (level) {
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
        }
        return "UNKNOWN";
    }

public:
    // Destructor (RAII cleanup)
    ~Logger() {
        if (file.is_open()) {
            file.close();
        }
    }

    // Global access point (Meyers Singleton)
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(LogLevel level, const string& message) {
        lock_guard<mutex> lock(mtx);

        string logMsg = "[" + levelToString(level) + "] " + message;

        // Console
        cout << logMsg << endl;

        // File
        file << logMsg << endl;
        file.flush();
    }

    void info(const string& message) {
        log(LogLevel::INFO, message);
    }

    void warning(const string& message) {
        log(LogLevel::WARNING, message);
    }

    void error(const string& message) {
        log(LogLevel::ERROR, message);
    }
};


int main() {
    Logger& logger = Logger::getInstance();

    logger.info("Application started");
    logger.warning("Low disk space");
    logger.error("Failed to connect to database");

    return 0;
}
