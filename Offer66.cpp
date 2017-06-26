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


/*
P3-从头到尾打印链表
时间限制：1秒 空间限制：32768K 热度指数：245185
题目描述
输入一个链表，从尾到头打印链表每个节点的值
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> value;
        ListNode* pNode = head;
        while(pNode!=NULL)
            {
            value.push_back(pNode->val);
            pNode = pNode->next;
        }
	//翻转vector；
    reverse(value.begin(), value.end()); 
        return value;
    }
};


/*
P4-使用两个栈实现队列
时间限制：1秒 空间限制：32768K 热度指数：108921
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

class Solution
{
public:
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop() 
    {
        if (stack1.size() == 0 && stack2.size() == 0)
            printf("queue is empty");
        else if (stack2.size() == 0)
        {
            while(stack1.size()>0)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int data = stack2.top();
        stack2.pop();
        return data;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


/*
P6-斐波那契数列
时间限制：1秒 空间限制：32768K 
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/
class Solution {
public:
    int Fibonacci(int n) 
    {
        //if(n == 0)return 0;
        //else if(n == 1)return 1;
        //else return Fibonacci(n-1) + Fibonacci(n-2);
        
        int result[2] = {0, 1};
        if(n < 2)return result[n];
        int Plus1 = 0;
        int Plus2 = 1;
        int PlusN = 0;
        for(int i = 2; i <= n; i++)
        {
            PlusN = Plus1 + Plus2;
            Plus1 = Plus2;
            Plus2 = PlusN;
        }
        return PlusN;
    }
};

