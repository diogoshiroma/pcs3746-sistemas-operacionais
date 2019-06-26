#include<linux/linkage.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<linux/sched/signal.h>
#include<asm/current.h>
#include<linux/kernel.h>

asmlinkage long sys_cfs(void)
{
	struct task_struct* task;
	struct pidTime {
		long long unsigned int time;
		int pid;
	};
	struct pidTime lista[100];
	struct pidTime aux;
	int i = 0;
	int j = 0;
	int k = 0;

	for_each_process(task){
		lista[i].time = task->se.vruntime;
		lista[i].pid = task->pid;
		i++;
	}
	for (j=i-1; j>0; j--){
            for (k=0; k<j; k++){
            	if (lista[k].time > lista[k+1].time){
                     aux = lista[k];
                     lista[k] = lista[k+1];
                     lista[k+1] = aux;
            	}
            }
        }
	for(k = 0; k < i; k++){
		printk("pid: %d		vruntime: %llu", lista[k].pid, lista[k].time);
	}

}
