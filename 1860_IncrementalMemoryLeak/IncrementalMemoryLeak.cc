class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;
        while (max(memory1, memory2) >= time) {
            if (memory1 >= memory2) {
                memory1 -= time;
            } else {
                memory2 -= time;
            }
            ++time;
        }
        return {time, memory1, memory2};
    }
};

// O(1) solution

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
		// first step:
		// make m1 and m2 close
        int d = abs(memory1 - memory2);
        int k = sqrt(2L*d+0.25)-0.5;
        int total = (long)k*(k+1)/2;
        if (memory1 > memory2) {
            memory1 -= total;
        } else {
            memory2 -= total;
        }
        
		// swap m1 and m2 if necessary
        bool changed = false;
        if (memory2 > memory1) {
            swap(memory2, memory1);
            changed = true;
        }
		
		// get tail1 and tail2 from our equation
        int start = k+1;
        int t1 = sqrt(4L*memory1 + (long)start*(start-2) + 1L) - 1.0;
        int t2 = sqrt(4L*memory2 + (long)start*start) - 1.0;
		
		// checking parity
        if ((start&1) ^ (t1&1)) --t1;
        if (((start+1)&1) ^ (t2&1)) --t2;

		// get crash time, as well as the final stage of m1/m2
        int time = max(t1, t2)+1;
        memory1 -= (long)(start+t1)*(t1-start+2)/4;
        memory2 -= (long)(start+t2+1)*(t2-start+1)/4;
        
		// swap m1, m2 if needed
        if (changed) {
            return {time, memory2, memory1};
        }
        return {time, memory1, memory2};
    }
};