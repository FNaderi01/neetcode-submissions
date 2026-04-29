class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++){
            bool r[10] = {false};
            for(int j =0; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                if(r[board[i][j]-'0'])
                    return false;
                r[board[i][j]-'0'] = true;
            }
        }

        for(int i=0; i<9; i++){
            bool r[10] = {false};
            // for(int p=0; p<10; p++){cout<<r[p]<<endl;}
            for(int j =0; j<9; j++){
                if(board[j][i] == '.')
                    continue;
                if(r[board[j][i]-'0'])
                    return false;
                r[board[j][i]-'0'] = true;
            }
        }


        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                bool r[10] = {false};
                for(int k = (i*3); k< (i+1)*3 ; k++){
                    for(int m = (j*3); m<(j+1)*3 ; m++){
                        if(board[k][m] == '.')
                            continue;
                        if(r[(board[k][m]-'0')])
                            return false;
                        r[board[k][m] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
};
