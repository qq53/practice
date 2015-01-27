/// \file ConvertBinarySearchTreeToDoubleList.cpp
/*
  ------------------------------------
  Create date : 2015-01-27 20:34
  Modified date: 2015-01-27 21:24
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;


/*  下面是一棵搜索二叉书
 *    4
 *  3   6
 *1  2 5  7
 *  你需要转换成双向有序链表 1<->2<->3....<->7
 */
int main(){
	char preorder[] = "431##2##65##7##";
	
	try{
		BinaryTreeNode *root = CreateBinaryTree(preorder);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
