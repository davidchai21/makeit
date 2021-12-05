class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int duration = releaseTimes[0];
        char key = keysPressed.front();
        for (int i=1;i<keysPressed.size();++i) {
            int diff = releaseTimes[i] - releaseTimes[i-1];
            if (diff > duration || diff == duration && key < keysPressed[i]) {
                key = keysPressed[i];
                duration = diff;
            }
        }
        return key;
    }
};