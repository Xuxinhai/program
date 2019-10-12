#include<iostream> 
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

struct job{
	string name;
	int inTime;			//进入时间
	int cost; 			//估计运行时间
	int currentCost; 	//当前剩余时间 
	int start;	 		//开始时间 
	int end;			//结束时间 
	int zzTime; 		//周转时间 
	double dqzzTime; 	//带权周转时间 
};

struct cmp{
	bool operator()(job a,job b){
		return a.cost > b.cost;
	}
};

double T,W;
queue<job> jobs;	//作业到来队列 
priority_queue<job,vector<job>,cmp> jobq,procq; //等待队列和进程调度队列（大小为2） 
vector<job> ans; 

void init(){
	int n;
	printf("输入作业个数：");
	scanf("%d",&n);
	job temp;
	int h,m;
	for(int i = 1;i <= n;i++){
		printf("输入作业名："); 
		cin >> temp.name;
		printf("输入进入时间："); 
		scanf("%d:%d",&h,&m);
		temp.inTime = h*60+m;
		printf("输入估计运行时间：");
		scanf("%d",&temp.cost);
		temp.currentCost = temp.cost;
		jobs.push(temp);
	} 
		
}

void arrange(){
	int i = jobs.front().inTime;
	
	//对每一分钟进行判断 
	while(1){ 
		//还有剩余作业且到达了进入时间 
		while(!jobs.empty() && jobs.front().inTime <= i){	
			jobq.push(jobs.front());	//进入等待队列 
			jobs.pop();
		}
	
		//判读是否有job完成 
		if(!procq.empty()){	
			job now = procq.top();
			if(now.currentCost == 0){
				now.end = i;
				procq.pop();
				ans.push_back(now);
			}
		}
		
		//若进程队列还有余量则将等待队列头的job调入 
		while(procq.size() < 2 && !jobq.empty()){
			if(!jobq.empty()){
				job now = jobq.top();
				jobq.pop();
				now.start = i;
				procq.push(now);				
			}
		}
		
		//处理进程队列头的job，每分钟currentCost减一 
		if(!procq.empty()){
			job now = procq.top();
			procq.pop();
			now.currentCost--;
			procq.push(now);
		}
		
		//若所有job均结束，直接退出			
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
	printf("作业平均周转时间 T=%lf\n",T/ans.size());
	printf("作业代权平均周转时间 W=%lf\n",W/ans.size());
	
}

int main(){
	init(); 	//初始化输入 
	arrange();	//作业调度	 
	print();	//打印结果 
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
