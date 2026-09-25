class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, int> keyValue;
    unordered_map<int, int> keyFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;

    void touch(int key) {
        int f = keyFreq[key];
        freqList[f].erase(keyIter[key]);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }
        keyFreq[key] = f + 1;
        freqList[f + 1].push_front(key);
        keyIter[key] = freqList[f + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) return -1;
        touch(key);
        return keyValue[key];
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key] = value;
            touch(key);
            return;
        }

        if ((int)keyValue.size() == capacity) {
            int evictKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            keyValue.erase(evictKey);
            keyFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }

        keyValue[key] = value;
        keyFreq[key] = 1;
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};