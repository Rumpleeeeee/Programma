/*
P1-查找

时间限制：1秒 空间限制：32768K 热度指数：302773

题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = 0;
        int col = 0;
        row = array.size();
        col = array[0].size();    
        int Crow = 0;
        int Ccol = col-1;
        while(Crow < row && Ccol >= 0){
            if(array[Crow][Ccol] == target){
                return true;
                }
            else if(array[Crow][Ccol] > target) Ccol--;
            else Crow++;               
        }
        return false;
    }
};


/*
P2-替换

时间限制：1秒 空间限制：32768K 热度指数：272898

题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str == NULL || length <= 0)return;
        int num_N = 0;
        int NewLength = 0;
        for(int i = 0; i < length; i++)
            if(str[i] == ' ')num_N++;
        NewLength = length + num_N * 2;
        
        for(int i = length; i >= 0; i--){
            if(str[i] == ' '){
                str[NewLength--] = '0';
                str[NewLength--] = '2';
                str[NewLength--] = '%';
            }
            else
                str[NewLength--] = str[i];
        }

	}
};
