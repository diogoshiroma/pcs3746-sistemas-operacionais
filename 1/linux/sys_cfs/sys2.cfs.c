#include <linux/linkage.h>
#include <linux/module.h>

#include <asm/barrier.h>
#include <linux/list.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/wait.h>

/*
static int process_list(struct task_struct *p)
{
   pr_info("BATATA\n");
   return 0;
}
*/

struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) 
                                  malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 

void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first print data of node */
     printf("%d ", node->data);   
  
     /* then recur on left sutree */
     printPreorder(node->left);   
  
     /* now recur on right subtree */
     printPreorder(node->right); 
} 

asmlinkage long sys_cfs(void)
{
   /* 
	struct task_struct *p = find_task_by_vpid(pid);
	return process_list(p);	
   */

   struct task_struct* task_pai = current;
	struct task_struct* task;
	struct sched_entity tututu = task_pai->se;
	struct list_head* lista;
	
	while(task_pai->pid != 1 ){
      task_pai=task_pai->parent;
		tututu = task_pai->se;
	}

	
	list_for_each(lista, &current->parent->children) {
      task = list_entry(lista, struct task_struct, sibling);
	   pr_info("pid eh -> %d\npid do parent -> %d", task->pid, task->parent->pid);
   
      if(task->pid == 45) {
         pr_info("FOREACH INIT");
         for_each_process(task) {
         /* this pointlessly prints the name and PID of each task */
            pr_info("FOREACH pid = [%d]\n", task->pid);
         }
         pr_info("FOREACH FINISH");
      }
    /* task now points to one of current's children */
	}

	return task;
}
