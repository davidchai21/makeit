class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        index = 0;
        w = width;
        h = height;
        body.push_back(make_pair(0,0));
        s.insert(make_pair(0,0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int x = body.front().first;
        int y = body.front().second;
        if (direction == "U") --x;
        else if (direction == "L") --y;
        else if (direction == "R") ++y;
        else if (direction == "D") ++x;
        
        if (x<0 || y<0 || x>=h || y>=w || s.find(make_pair(x,y)) != s.end() && (make_pair(x,y)!=body.back())) return -1;
        if (index<food.size() && x==food[index][0] && y==food[index][1]) {
            ++index;
            s.insert(make_pair(x,y));
            body.push_front(make_pair(x,y));
        } else {
            s.erase(body.back());
            body.pop_back();
            s.insert(make_pair(x,y));
            body.push_front(make_pair(x,y));
        }
        return body.size()-1;
    }
private:
    vector<vector<int>> food;
    deque<pair<int,int>> body;
    set<pair<int,int>> s;
    int index;
    int w, h;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */