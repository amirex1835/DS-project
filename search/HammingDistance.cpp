#include "HammingDistance.h"
#include <algorithm>

int hammingDistance(const string& a, const string& b) {
    int minLen = min(a.size(), b.size());
    int distance = 0;

    for (int i = 0; i < minLen; i++) {
        if (a[i] != b[i])
            distance++;
    }

    distance += abs((int)a.size() - (int)b.size());
    return distance;
}
