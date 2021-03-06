bool search(vector<int> A, int val){
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == val)
            return true;
    }
    return false;
}

int Solution::isValidSudoku(const vector<string> &A) {
    unordered_map<int, vector<int> > myMap;
    for(int i = 0; i < A.size(); i++)       //row checking
    {
        string temp = A[i];
        for(int j = 0; j < temp.size(); j++)
        {
            int c = temp[j];
            if(isdigit(c))
            {
                if(myMap.find(i) != myMap.end())
                {
                    if(search(myMap[i], c)){
                        return 0;
                    }
                }
                myMap[i].push_back(c);
            }
        }
    }
    unordered_map<int, vector<int> > myMap1;
    for(int i = 0; i < 9; i++)       //column checking
    {
        for(int j = 0; j < A.size(); j++)
        {
            string temp = A[j];
            int c = temp[i];
            if(isdigit(c))
            {
                if(myMap1.find(i) != myMap1.end())
                {
                    if(search(myMap1[i], c))
                        return 0;
                }
                myMap1[i].push_back(c);
            }
        }
    }
    unordered_map<int, vector<int> > myMap2;
    int box = 0;
    int count = 0;
    int row = 0;
    while(box != 9)         //9*9 Box checking
    {
        for(int i = 3*row; i < 3*(row+1); i++)
        {
            string temp = A[i];
            for(int j = 3*count; j < 3*(count+1); j++)
            {
                int c = temp[j];
                if(isdigit(c))
                {
                    if(myMap2.find(box) != myMap1.end())
                    {
                        if(search(myMap2[box], c))
                            return 0;
                    }
                    myMap2[box].push_back(c);
                }
            }
        }
        count++;
        box++;
        if(box == 3 || box == 6)
        {
            row++;
            count = 0;
        }
    }
    return 1; //if all condition paas
}

