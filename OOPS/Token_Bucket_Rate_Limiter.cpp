/*
5️⃣ Core Design Decisions
Aspect	        Choice

Algorithm	    Token Bucket
Granularity	    Per user
Thread-safe	    Yes
Time source	    steady_clock
Data structure	unordered_map

*/

#include <bits/stdc++.h>
using namespace std;

class RateLimiter {
private:
    struct Bucket {
        double tokens;
        chrono::steady_clock::time_point lastRefill;
    };

    unordered_map<string, Bucket> userBuckets;
    mutex mtx;

    const double capacity;
    const double refillRate; // tokens per second

public:
    RateLimiter(double maxTokens, double refillRatePerSec)
        : capacity(maxTokens), refillRate(refillRatePerSec) {}

    bool allowRequest(const string& userId) {
        lock_guard<mutex> lock(mtx);

        auto now = chrono::steady_clock::now();
        auto& bucket = userBuckets[userId];

        if (bucket.lastRefill.time_since_epoch().count() == 0) {
            bucket.tokens = capacity;
            bucket.lastRefill = now;
        }

        // Refill tokens
        double elapsed =
            chrono::duration<double>(now - bucket.lastRefill).count();

        bucket.tokens = min(
            capacity,
            bucket.tokens + elapsed * refillRate
        );

        bucket.lastRefill = now;

        // Consume token
        if (bucket.tokens >= 1) {
            bucket.tokens -= 1;
            return true;
        }

        return false;
    }
};

int main()
{
    RateLimiter limiter(5, 1); // 5 tokens, 1 token/sec

    string user = "user123";

    for (int i = 1; i <= 10; i++)
    {
        if (limiter.allowRequest(user))
        {
            cout << "Request " << i << " allowed\n";
        }
        else
        {
            cout << "Request " << i << " blocked\n";
        }
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}
