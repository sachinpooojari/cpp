#include   <stdio.h> 
#include<stdlib.h>
#include<string.h>
#define MAX 100


void copy_file(FILE *sf,FILE *df)    ///source->dest
{
	char ch;
	while((ch=getc(sf))!=EOF)
	{
		fputc(ch,df);

	}
}

void after_found_symbols(char *name1,FILE *dp)

{

	FILE *tmp_file;

	printf("Name  : %s\n ",name1);
	tmp_file=fopen(name1,"r");
	if(tmp_file==NULL)
	{
		printf("%s Library File doesnt exist \n ",name1);
		exit(0);

	}

	copy_file(tmp_file,dp);
	fclose(tmp_file);

}
void found_define(FILE* fp,FILE* dp,char* s)
{
//	printf(" ?<%s>? ",s);;
	char str[MAX]=" ";
	char data[MAX]=" ";
	char ch;
	fscanf(fp,"%s", str);
	
	int i=0;
	while((ch=fgetc(fp))!='\n')
		data[i++]=ch;
	data[i]=0;

//	printf(" ***<%s>***\n ",str);;

//	printf(" |<***<%s>*** >| \n",data);
	int F_pointer=0;
	F_pointer=ftell(fp);
	

//	printf("| %d |\n",F_pointer);
	// fscanf(fp,"%s",s) != EOF)
/*	char cmp_str[MAX];
	while( fscanf(fp,"%s",cmp_str) != EOF)
	{
		if(strcmp(cmp_str,str)==0)
			printf("\nFFFOOOUUNND\n");
		
	
	
	}
*/	
	//fseek(fp,F_pointer,SEEK_SET);   //to set pointer back


}	


void remove_comment(FILE *fp,FILE *dp)
{
	char ch,ch1,tmp[MAX];
	while((ch=fgetc(fp))!=EOF)
	{	//embedd here error code 
		if(ch== '/')
		{ 
			ch1=fgetc(fp);
			if(ch1=='/')
				fgets(tmp,MAX,fp);
			else if(ch1=='*')
			{

				L:	while( ((ch1=fgetc(fp))!='*') );
				
				if( (ch1=fgetc(fp))!='/') 
				{
					goto L;     //  if only * present with no / the loopback
				}
				
			}
			else
			{
				fputc(ch,dp);   // if not comment put /  and next char to file.
				fputc(ch1,dp);   // if not comment put /  and next char to file.
			}	
				
		}
		else 
		{
			 fputc(ch,dp);
		
		}

	}
	

}














void found_include(FILE *fp,FILE *dp,char *s)
{	
	char ch;
	char name1[10]=" ";
	char name2[10]=" ";
	int len=strlen(s);
	fseek(fp,-len,SEEK_CUR);   // to point back pointer at start of #include to avoid erors.
	while((ch=fgetc(fp))!=EOF)
	{	//embedd here error code 
		if(ch== '"')
		{ 	int i=0;	

			while((ch=fgetc(fp))!='"')
			{
				name1[i++]=ch;

			}


			after_found_symbols(name1,dp);
			return;

		}

		else if(ch== '<')
		{ 	int i=0;	

			while((ch=fgetc(fp))!='>')
			{
				name2[i++]=ch;
			}

			after_found_symbols(name2,dp);
			return;
		}





	}


}




																

int  main(int argc ,char**  argv)

{	


	if(argc<2)
	{
		puts("Usage of commane :  ./a.out fname\n");
		return 0;
	}

	FILE *fp,*dp;
	fp=fopen(argv[1],"r");
	//case2  and 3

	char tmp[strlen(argv[1])+2];   //tmp string to create .i file 
	strcpy(tmp,argv[1]);
	strcat(tmp,".i");;


	char s[MAX];
	int pointer=0;

	dp=fopen("temp.tmp","w");   // dp -> temprory file which used to put commented data 
	remove_comment(fp,dp);
	fclose(dp);
	fclose(fp);

	fp=fopen("temp.tmp","r");    /// now this temrory file become source file 
	dp=fopen(tmp,"w");   // dp -> .i file in write mode. i
		
	int F_pointer=0;
	while( fscanf(fp,"%s",s) != EOF)
	{
		if(strstr(s,"#include"))
		{
			found_include(fp,dp,s);
			F_pointer=ftell(fp);
		}
//		printf("%s ",s);
		else if(strstr(s,"#define"))
		{
			found_define(fp,dp,s);	
			F_pointer=ftell(fp);
		
		}
		
	}
	fseek(fp,F_pointer,SEEK_SET);
	printf("%d",F_pointer);
	char ch;
	while((ch=getc(fp))!=EOF)
		fputc(ch,dp);
	
		
	
		

}
