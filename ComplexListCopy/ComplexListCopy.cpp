/// \file ComplexListCopy.cpp
/*
  ------------------------------------
  Create date : 2015-01-25 22:32
  Modified date: 2015-01-25 23:14
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

struct complexList{
	int m_nValue;
	complexList *m_pNext;
	complexList *m_pSibling;
};

complexList *CreateComplexNode(int value){
	complexList *pNode = new complexList();

	pNode->m_nValue = value;
	pNode->m_pNext = pNode->m_pSibling = NULL;

	return pNode;
}

void BuildComplexNode(complexList *pNode, complexList *pNext, complexList *pSibling){
	if(pNode == NULL)
		throw myException("empty pNode");
	pNode->m_pNext = pNext;
	pNode->m_pSibling = pSibling;
}

int main(){
	int array = {1,2,3,4};
	complexList *pHead = CreateComplexList();
}
