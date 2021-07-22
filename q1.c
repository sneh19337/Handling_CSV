#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define MAX 50
//structure of arrays to store the values from the csv file
typedef struct key_value
{
    char rno[50];
    char grade[50];
    char assign1[50];
    char assign2[50];
    char assign3[50];
    char assign4[50];
    char avg[50];
}dict;
//main function of the program 
int main()
{
    FILE *fp= fopen("file.csv","r");
    if(!fp)
    {
        write(1,"An error while opening the file",33);
        exit(1);
        return 0;
    }
    char buf[MAX];
    char buff[800];
    int row_count=0;
    int filed_count=0;
    dict values[410];
    int i=0;
    double sum[]={0};
    double avg=0;
    while(fgets(buff,200,fp))
    {
        filed_count=0;
        row_count++;
        if(row_count==1)
            continue;
        char *filed=strtok(buff,",");
        while(filed)
        {
            if(filed_count==0)
                strcpy(values[i].rno,filed);
            if(filed_count==1)
                strcpy(values[i].grade,filed);
            if(filed_count==2)
                strcpy(values[i].assign1,filed);
            if(filed_count==3)
                strcpy(values[i].assign2,filed);
            if(filed_count==4)
                strcpy(values[i].assign3,filed);
            if(filed_count==5)
                strcpy(values[i].assign4,filed);
            filed=strtok(NULL,",");
            filed_count++;
        }
                i++;
        }
        
             for(int i=0;i<410;i++)
     {
       //changing the string values to the floating  point numbers using atof 
    sum[i]=(atof(values[i].assign1)+atof(values[i].assign2)+atof(values[i].assign3)+atof(values[i].assign4))/4;
    gcvt(sum[i],6,buf);
    strcpy(values[i].avg,buf);

    }
    //creating a chid process
pid_t child;
//forking to obtain the child
child=fork();
for(int i=0;i<410;i++){
if(child==0)
{
    //child process
    if(*(values[i].grade)== 'A')
        {
            //printf("Roll No ->%s , Section  ->%s, Assignment1  ->%s, Assignment2 ->%s ,Assignment3 ->%s ,Assignment4 ->%s , Average marks->%0.2f \n", values[i].rno,values[i].grade,values[i].assign1,values[i].assign2,values[i].assign3,values[i].assign4,sum[i]);
            
           //used write to get all the details of the students
            write(1,"rollno--> ",10);
            write(1,values[i].rno,5);
            write(1,"  section--> ",10);
            write(1,values[i].grade  ,10);
            write(1,"  Assignment1--> ",15);
            write(1,values[i].assign1,5);
            write(1,"  Assignment2--> ",15);
            write(1,values[i].assign2,5);
            write(1,"  Assignment3--> ",15);
            write(1,values[i].assign3,5);
            write(1,"  Assignment4--> ",15);
            write(1,values[i].assign4,5);
            write(1," Average Marks--> ",15);
            write(1,values[i].avg,6);
            write(1,"\n",5);

            //printf("  Average Marks-->%0.2f\n",sum[i]);
            //w
            }


}
        
else
{
 //waiting for the child process to finish  
    waitpid(child,NULL,0);
    
    //exiting the child process after completion
    exit(0);

    

}
//parent process after child is over
if(*(values[i].grade)== 'B')
        
        {
           
          // printf("Roll No->%s , Section ->%s, Assignment1->%s, Assignment2->%s ,Assignment3->%s ,Assignment4->%s , Average marks->%0.2f \n", values[i].rno,values[i].grade,values[i].assign1,values[i].assign2,values[i].assign3,values[i].assign4,sum[i]);
            write(1,"rollno--> ",10);
            write(1,values[i].rno,3);
            write(1,"  section--> ",10);
            write(1,values[i].grade  ,3);
            write(1,"  Assignment1--> ",15);
            write(1,values[i].assign1,5);
            write(1,"  Assignment2--> ",15);
            write(1,values[i].assign2,5);
            write(1,"  Assignment3--> ",15);
            write(1,values[i].assign3,5);
            write(1,"  Assignment4--> ",15);
            write(1,values[i].assign4,5);
            write(1," Average Marks--> ",15);
            write(1,values[i].avg,6);
            write(1,"\n",5);
            //printf("  Average Marks-->%0.2f\n",sum[i]);  
        }
    
}
    

//closing the file
    fclose(fp);
    return 0;

}


