class Solution {
public:
    vector<vector<string>> answer;
    vector<string> answerTemp;
    string callHelper(string qsf, int row, int col){

            string temp;
            char chR = row + '0';
            char chC = col + '0';
            temp.push_back(chR);
            temp.push_back('-');
            temp.push_back(chC);
            temp.push_back(',');

            qsf += temp;
            
            return qsf;
    }


    bool isitSafe(vector<vector<int>> &chess, int row, int col){

        for(int i = row - 1, j = col; i>=0; i--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row - 1, j = col - 1; i>=0 && j>=0; i--, j--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row - 1, j = col+1; i>=0 && j<chess.size(); i--, j++){
            if(chess[i][j] == 1){
                return false;
            }
        }
        return true;
    }


    vector<string> makeAnswer(string qsf, int N){
        string str, temp;
        vector<string> sf;
        int i=0;
        while(i<N){
            str.push_back('.');
            i++;
        }
        
        for(int i=2; i<qsf.size(); i=i+4){
            temp = str;
            char ch = qsf[i];
            temp[(int)qsf[i]-'0'] = 'Q';
            sf.push_back(temp);
        } 
        
        return sf;
    }
    
    void printNQueens(vector<vector<int>> &chess, string qsf, int row){
        if(row == chess.size()){
            //cout<<qsf<<endl;
            vector<string> v = makeAnswer(qsf,chess.size());
            answer.push_back(v);
            return;
        }

        for(int col=0; col<chess.size(); col++){
            bool res = isitSafe(chess, row, col);
            if(res == true){
                chess[row][col] = 1;

                printNQueens(chess, callHelper(qsf, row, col), row+1);

                chess[row][col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int i=0;

        vector<vector<int>> chess(n, vector<int> (n, 0));
        printNQueens(chess, "", 0);
        
        return answer;
    }
};