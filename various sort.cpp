#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> commonSort(vector<int> before)
{
	vector<int>::iterator itr;
	vector<int>::iterator itr_after;
	int restore;
	int loopnum=0;
	
	for(itr=before.begin();itr!=before.end();++itr)
	{
		for(itr_after=itr+1;itr_after!=before.end();++itr_after)
		{
			++loopnum;
			if((*itr)>(*itr_after))
			{
				restore=(*itr);
				(*itr)=(*itr_after);
				(*itr_after)=restore;
			}
		}
	}
	cout<<"CS loopcount : "<<loopnum<<endl;
	return before;
}

vector<int> InsertSort(vector<int> before)
{
	vector<int> after;
	vector<int>::iterator itr;
	vector<int>::iterator itr_after;
	int count=0;
	int idx=0;
	bool isinsert=0;
	int len=0;
	int loopnum=0;
/*	
	for(idx=0, itr=before.begin();itr!=before.end();++itr, ++idx)
	{
		cout<<"index : "<<idx<<" value : "<<(*itr)<<endl;
	}*/
	for(itr=before.begin();itr!=before.end();++itr)
	{
//		cout<<"work?"<<endl;
		if(after.size()==0)
		{
			after.push_back((*itr));
		}
		else
		{
			for(count=0, itr_after=after.begin();itr_after!=after.end();++itr_after)
			{
				++loopnum;
				len=after.size();
//				cout<<(*itr)<<", "<<(*itr_after)<<endl;
				if((*itr)<=(*itr_after))
				{
//					cout<<"work?"<<" idx : "<<count<<" length : "<<len<<endl;
					after.insert(after.begin()+count, (*itr));
					isinsert=1;
					break;
				}
				else
				{
//					cout<<"really?"<<" idx : "<<count<<" length : "<<len<<endl;
					isinsert=0;
					++count;
					continue;
				}
			}
			if(!isinsert)
			{
				after.push_back((*itr));
			}
		}
	}
	cout<<"IS loopcount : "<<loopnum<<endl;
	return after;
}

vector<int> SelectSort(vector<int> before)
{
	vector<int> after;
	vector<int>::iterator itr_before;
	int restore=0;
	int restore_idx=0;
	int len=0;
	int idx=0;
	int loopnum=0;
	len=before.size();
	
	while(after.size()<len)
	{
		restore=*(before.begin());
		restore_idx=0;
		for(itr_before=before.begin(), idx=0;itr_before!=before.end();++itr_before, ++idx)
		{
			++loopnum;
			if(*itr_before<restore)
			{
				restore=(*itr_before);
				restore_idx=idx;
			}
		}
//		cout<<restore<<", "<<restore_idx<<endl;		
		after.push_back(restore);
		before.erase(before.begin()+restore_idx);
	}
	cout<<"SS loopcount : "<<loopnum<<endl;
	return after;
}

int Binarysearch(vector<int> sorted, int who)
{
	int where=0;
	int len=sorted.size();
	vector<int>::iterator itr;
	
	itr=sorted.begin();

	if(len%2==1)
	{
		where=(len-1)/2;
	}
	else
	{
		where=len/2;	
	}
	
	while(len>1)
	{
		if(len%2==1)
		{
			len--;
		}
		len/=2;
		if(who<*(itr+where))
		{
			where-=len;
		}
		else if(who>*(itr+where))
		{
			where+=len;
		}
		else
		{
			break;
		}
	}
	return where;
}

int BinarysearchA(vector<int> sorted, int who)
{
	vector<int>::iterator itr;
	int len=sorted.size();
	int mid=len/2;
	int sp=0;
	int ep=len-1;
	itr=sorted.begin();

	while(sp<=ep)
	{
		mid=(sp+ep)/2;
		if(who>*(itr+mid))
		{
			sp=mid+1;
		}
		else if(who<*(itr+mid))
		{
			ep=mid-1;
		}
		else
		{
			return mid;
		}
	}
	if(sp>ep)
	{
		mid=sp;
	}
	return mid;
}

vector<int> BinaryInsertSort(vector<int> before)
{
	vector<int> after;
	vector<int>::iterator itr;
	vector<int>::iterator itr_after;
	vector<int>::iterator confirm;
	int count=0;
	int idx=0;
	bool isinsert=0;
	int len=0;
	int loopnum=0;
	int where=0;

	for(itr=before.begin();itr!=before.end();++itr)
	{
		if(after.size()==0)
		{
			after.push_back((*itr));
		}
		else
		{	
			isinsert=0;
			len=after.size();
			itr_after=after.begin();
			
			if(len==1)
			{
				if((*itr)<(*itr_after))
				{
					after.insert(after.begin(),(*itr));
					isinsert=1;
				}
				else
				{
					after.push_back((*itr));
					isinsert=1;
				}
			}
			else if(len>1)
			{
/*				if(len==3)
				{
					for(count=0, confirm=after.begin();confirm!=after.end();++confirm, ++count)
					{
						if(*confirm<*itr)
						{
							continue;
						}
						else
						{
							break;
						}
					}
					after.insert(after.begin()+count,*itr);
					isinsert=1;
				}*/
				if(len%2==1)
				{
					len=(len-1)/2;
					where=len;
				}
				else
				{
					len/=2;
					where=len;				
				}			
			}

			while(len>1)
			{
//				cout<<where<<", "<<len<<", "<<after.size()<<endl;
				++loopnum;
				if(len%2==1)
				{
					len--;
				}
				len/=2;
				if((*itr)<*(itr_after+where))
				{
					where-=len;
				}
				else if((*itr)>*(itr_after+where))
				{
					where+=len;
				}
				else
				{
					break;
				}
			}
//			cout<<where<<", "<<after.size()<<endl;
			if(!isinsert)
			{
				after.insert(after.begin()+where, (*itr));
			}
		}
		for(count=0, confirm=after.begin();confirm!=after.end();++confirm, ++count)
		{
			cout<<"index : "<<count<<", value : "<<*confirm<<endl;
		}
		cout<<"next"<<endl;
	}
	cout<<loopnum<<endl;
	return after;
}

vector<int> BinaryInsertSortA(vector<int> before)
{
	int count=0;
	int idx=0;
	int sp=0;
	int ep=0;
	int mid=0;
	int loopcount=0;
	bool isInsert=0;
	int sizeA=0;
	int sizeB=0;
	vector<int> after;
	vector<int>::iterator b_itr;
	vector<int>::iterator a_itr;

	after.push_back(*before.begin());
	sizeB=before.size();
	b_itr=before.begin();
	
	for(idx=0;idx<sizeB;++idx)
	{
		isInsert=0;
		sizeA=after.size();
		sp=0;
		ep=sizeA-1;
		a_itr=after.begin();
		while(sp<=ep)
		{
			loopcount++;
			mid=(sp+ep)/2;
			if(*(b_itr+idx)>*(a_itr+mid))
			{
				sp=mid+1;
			}
			else if(*(b_itr+idx)<*(a_itr+mid))
			{
				ep=mid-1;
			}
			else
			{
				count=mid;
				isInsert=1;
				break;
			}
		}
		if(!isInsert&&sp>ep)
		{
			count=sp;
		}
		after.insert(a_itr+count,*(b_itr+idx));
	}
	cout<<"BIS loopcount : "<<loopcount<<endl;
	return after;
}

void CStest(vector<int> unsorted)
{
	vector<int> sorted_cs;
	vector<int>::iterator itr_cs;
	sorted_cs=commonSort(unsorted);
	for(itr_cs=sorted_cs.begin();itr_cs!=sorted_cs.end();++itr_cs)
	{
		cout<<*(itr_cs)<<" | ";
	}
	cout<<endl;
}

void IStest(vector<int> unsorted)
{
	vector<int> sorted_is;
	vector<int>::iterator itr_is;
	sorted_is=InsertSort(unsorted);
	for(itr_is=sorted_is.begin();itr_is!=sorted_is.end();++itr_is)
	{
		cout<<*(itr_is)<<" | ";
	}
	cout<<endl;
}

void SStest(vector<int> unsorted)
{
	vector<int> sorted_ss;
	vector<int>::iterator itr_ss;
	sorted_ss=SelectSort(unsorted);
	for(itr_ss=sorted_ss.begin();itr_ss!=sorted_ss.end();++itr_ss)
	{
		cout<<*(itr_ss)<<" | ";
	}
	cout<<endl;
}

void BIStest(vector<int> unsorted)
{
	vector<int> sorted_bis;
	vector<int>::iterator itr_bis;
	sorted_bis=BinaryInsertSortA(unsorted);
	for(itr_bis=sorted_bis.begin();itr_bis!=sorted_bis.end();++itr_bis)
	{
		cout<<*(itr_bis)<<" | ";
	}
	cout<<endl;
}

int main(void)
{
	int i=0;
	vector<int> unsorted;
	vector<int>::iterator us_itr;
	for(i=0;i<100;++i)
	{
		unsorted.push_back(rand()%100);
	}
	for(us_itr=unsorted.begin();us_itr!=unsorted.end();++us_itr)
	{
		cout<<*(us_itr)<<" | ";
	}
	cout<<endl;
	CStest(unsorted);
	IStest(unsorted);
	SStest(unsorted);
	BIStest(unsorted);
	
	return 0;
}
