#include<iostream> 
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

struct job{
	string name;
	int inTime;			//����ʱ��
	int cost; 			//��������ʱ��
	int currentCost; 	//��ǰʣ��ʱ�� 
	int start;	 		//��ʼʱ�� 
	int end;			//����ʱ�� 
	int zzTime; 		//��תʱ�� 
	double dqzzTime; 	//��Ȩ��תʱ�� 
};

struct cmp{
	bool operator()(job a,job b){
		return a.cost > b.cost;
	}
};

double T,W;
queue<job> jobs;	//��ҵ�������� 
priority_queue<job,vector<job>,cmp> jobq,procq; //�ȴ����кͽ��̵��ȶ��У���СΪ2�� 
vector<job> ans; 

void init(){
	int n;
	printf("������ҵ������");
	scanf("%d",&n);
	job temp;
	int h,m;
	for(int i = 1;i <= n;i++){
		printf("������ҵ����"); 
		cin >> temp.name;
		printf("�������ʱ�䣺"); 
		scanf("%d:%d",&h,&m);
		temp.inTime = h*60+m;
		printf("�����������ʱ�䣺");
		scanf("%d",&temp.cost);
		temp.currentCost = temp.cost;
		jobs.push(temp);
	} 
		
}

void arrange(){
	int i = jobs.front().inTime;
	
	//��ÿһ���ӽ����ж� 
	while(1){ 
		//����ʣ����ҵ�ҵ����˽���ʱ�� 
		while(!jobs.empty() && jobs.front().inTime <= i){	
			jobq.push(jobs.front());	//����ȴ����� 
			jobs.pop();
		}
	
		//�ж��Ƿ���job��� 
		if(!procq.empty()){	
			job now = procq.top();
			if(now.currentCost == 0){
				now.end = i;
				procq.pop();
				ans.push_back(now);
			}
		}
		
		//�����̶��л��������򽫵ȴ�����ͷ��job���� 
		while(procq.size() < 2 && !jobq.empty()){
			if(!jobq.empty()){
				job now = jobq.top();
				jobq.pop();
				now.start = i;
				procq.push(now);				
			}
		}
		
		//������̶���ͷ��job��ÿ����currentCost��һ 
		if(!procq.empty()){
			job now = procq.top();
			procq.pop();
			now.currentCost--;
			procq.push(now);
		}
		
		//������job��������ֱ���˳�			
		if(jobs.empty() && jobq.empty() && procq.empty())
			break;
		i++;
	}
}

bool rule(job a,job b){
	return a.inTime < b.inTime;
}

void print(){
	sort(ans.begin(),ans.end(),rule);
	T=0,W=0;
	for(int i = 0; i< ans.size();i++){
		job now = ans[i];
		T += (now.end-now.inTime);
		W += ((now.end-now.inTime)*1.0/now.cost);
		printf("%s	%02d:%02d	%d	%02d:%02d	%02d:%02d	%d	%lf\n",
		now.name.c_str(),now.inTime/60,now.inTime%60,now.cost,now.start/60,now.start%60,
		now.end/60,now.end%60,now.end-now.inTime,(now.end-now.inTime)*1.0/now.cost);
	}
	printf("��ҵƽ����תʱ�� T=%lf\n",T/ans.size());
	printf("��ҵ��Ȩƽ����תʱ�� W=%lf\n",W/ans.size());
	
}

int main(){
	init(); 	//��ʼ������ 
	arrange();	//��ҵ����	 
	print();	//��ӡ��� 
	return 0;
}

/*
4
job1
10:00
30
job2
10:05
20
job3
10:10
5
job4
10:20
10
*/
