 CP::queue<int> q;
    for(int i=10;i<=60;i+=10)
    {
        q.push(i);
    }
    q.move_to_back(3);
    for(int i=0;i<6;i++)
    {
        cout << q.front() <<  ' ';
        q.pop();
    }