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
	cout<<loopnum<<endl;
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
	cout<<loopnum<<endl;
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
	cout<<loopnum<<endl;
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

int main(void)
{
	vector<int> unsorted;
	vector<int> sorted_cs;
	vector<int> sorted_is;
	vector<int> sorted_ss;
	vector<int> sorted_bis;
	vector<int>::iterator itr_is;
	vector<int>::iterator itr_cs;
	vector<int>::iterator itr_ss;
	vector<int>::iterator itr_bis;
	int i=0;
	int idx=0;
	int len=0;
	int find=0;
	
	for(i=0;i<32;++i)
	{
		unsorted.push_back(rand());
	}
	
	sorted_cs=commonSort(unsorted);
	sorted_is=InsertSort(unsorted);
	sorted_ss=SelectSort(unsorted);
	sorted_bis=BinaryInsertSort(unsorted);
//	find=Binarysearch(sorted_is, 15000);
//	len=sorted_is.size();
//	len=sorted_ss.size();
	
//	for(idx=0, itr=unsorted.begin();itr!=unsorted.end();++itr, ++idx)
/*	for(idx=0, itr_is=sorted_is.begin();itr_is!=sorted_is.end();++itr_is, ++idx)
	{
		cout<<"index : "<<idx<<" value : "<<(*itr_is)<<" length : "<<len<<endl;
	}*/
/*	for(idx=0, itr_ss=sorted_ss.begin();itr_ss!=sorted_ss.end();++itr_ss, ++idx)
	{
		cout<<"index : "<<idx<<" value : "<<(*itr_ss)<<" length : "<<len<<endl;
	}*//*
	for(idx=0, itr_bis=sorted_bis.begin();itr_bis!=sorted_bis.end();++itr_bis, ++idx)
	{
		cout<<"index : "<<idx<<" value : "<<(*itr_bis)<<" length : "<<len<<endl;
	}*/
	
	/*
	for(itr_is=sorted_is.begin(), itr_cs=sorted_cs.begin();itr_is!=sorted_is.end(), itr_cs!=sorted_cs.end();++itr_is, ++itr_cs)
	{
		if(*itr_is==*itr_cs)
		{
			cout<<"same"<<endl;
		}
		else
		{
			cout<<"differ"<<endl;
		}
	}*/
/*	for(itr_ss=sorted_ss.begin(), itr_cs=sorted_cs.begin();itr_ss!=sorted_ss.end(), itr_cs!=sorted_cs.end();++itr_ss, ++itr_cs)
	{
		if(*itr_ss==*itr_cs)
		{
			cout<<"same"<<endl;
		}
		else
		{
			cout<<"differ"<<endl;
		}
	}*/
	
	cout<<"index : "<<find<<endl;
	
	return 0;
}
