#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAX 12

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif


void menu(void);    // menu
void add(void);     // add user
void del(void);     // delete
void list(void);    // list of users
void upd(void);  //update the information

struct og
{
    char id[30];
    char tc[30];
    char name[30];
	char s_name[30];
    char tel[30];
    char adres[50];
}ogrenci[MAX],ogr[MAX];

FILE *kp;

char s_id[15]; // for getting search id

int p,i=0,say=0;


main()
{
    menu();
	return 0;
}


void menu()
{
    char sec;
    do
	{
    printf("\n\n\n\t########MAIN   MENU########\n\n");
	printf("\n\t[A]-ADD NEW STUDENT\n");
	printf("\t[D]-DELETE\n");
	printf("\t[U]-UPDATE\n");
	printf("\t[L]-LIST\n");
 	printf("\t[Q]-QUIT\n");
	printf("\t\n\n\n\n");

    sec=getch(); // menü secimi burada
	if(sec=='A' || sec=='a')
	add();
	else if(sec=='D' || sec=='d')
	del();
	else if(sec=='U' || sec=='u')
	upd();
	else if(sec=='L' || sec=='l')
	list();
	}while((sec!='Q')&( sec!='q'));


}

/*******************************************/
/********KAYIT FORMU***********************/

void add()
{
	int a,k;
	system(CLEAR);
	//system("cls");
	if(p>12)
	printf("error! no free space\n");
	else
	{
    if((kp=fopen("kayit.txt","a+"))==NULL)
    {
        printf("file not open\n\n");
    } //if


    else
    {
		// KONTROL ÝÇÝN DOSYADAN DEÐERLERÝ ALDIK
		k=0;
		while(!feof(kp))
	{
		fscanf(kp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",&ogrenci[k].id,&ogrenci[k].tc,&ogrenci[k].name,&ogrenci[k].s_name,&ogrenci[k].tel,&ogrenci[k].adres);
		strcpy(ogr[k].id,ogrenci[k].id);
		strcpy(ogr[k].tc,ogrenci[k].tc);
		strcpy(ogr[k].name,ogrenci[k].name);
		strcpy(ogr[k].s_name,ogrenci[k].s_name);
		strcpy(ogr[k].tel,ogrenci[k].tel);
		strcpy(ogr[k].adres,ogrenci[k].adres);
		k++;
	}//while
	a=k;

		printf("########ADD NEW STUDENT########");

        printf("\nenter id>\n");
        scanf("%s",ogrenci[i].id);

		//ID NO KONTROLÜ
		for(k=0; k<a; k++)
		{

		if(strcmp(ogrenci[i].id,ogr[k].id)==0)
		{
		printf("\nBu ID kullanilmaktadir!\n");
		ogrenci[i].id[0]='\0';
		printf("enter an another id>\n");
		scanf("%s",ogrenci[i].id);
		}//if
		}//for

		fprintf(kp,"%s\t\t",ogrenci[i].id);
		printf("\n");

      printf("enter tc no>\n");
      scanf("%s",ogrenci[i].tc);

	  //TC NO KONTROLÜ
	  for(k=0; k<a; k++)
		{

		if(strcmp(ogrenci[i].tc,ogr[k].tc)==0)
		{
		printf("\nBu TC NO kullanilmaktadir!\n");
		ogrenci[i].tc[0]='\0';
		printf("\nenter an another tc no>\n");
		scanf("%s",ogrenci[i].tc);
		}//if
		}//for

	  fprintf(kp,"%s\t\t",ogrenci[i].tc);
	  printf("\n");

        printf("\nenter name>\n");
        scanf("%s",ogrenci[i].name);
		fprintf(kp,"%s\t\t",ogrenci[i].name);
		printf("\n");

		printf("\nenter surname>\n");
        scanf("%s",ogrenci[i].s_name);
		fprintf(kp,"%s\t\t",ogrenci[i].s_name);
		printf("\n");

        printf("\nenter tel no>\n");
		scanf("%s",ogrenci[i].tel);
		fprintf(kp,"%s\t\t",ogrenci[i].tel);
		printf("\n");

        printf("\nenter addresses(use _ for space character)>\n");
        scanf("%s",ogrenci[i].adres);
		fprintf(kp,"%s\n",ogrenci[i].adres);
		printf("\n");
		p++;
        }
		fclose(kp);

    }//else

	printf("\nPRESS ANY BUTTON TO MAIN MENU !!!\n");
	getch();
	system("cls");


}//add

void list()
{

	if((kp=fopen("kayit.txt","r"))==NULL)
	{
		printf("can not open\n\n");
	}//if

	i=0;
	system(CLEAR);
	//system("cls");
	printf("\n\n######## LIST OF STUDENTS #########\n");
	while(!feof(kp))
	{

	fscanf(kp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",&ogr[i
].id,&ogr[i].tc,&ogr[i].name,&ogr[i].s_name,&ogr[i].tel,&ogr[i].adres);

		printf("###################################");
		printf("\nID: %s\n",ogr[i].id);

		printf("TC NO: %s\n",ogr[i].tc);

		printf("NAME: %s\n",ogr[i].name);

		printf("SURNAME: %s\n",ogr[i].s_name);

		printf("TEL NO: %s\n",ogr[i].tel);

		printf("ADDRESSES: %s\n",ogr[i].adres);

	}//while
	fclose(kp);

	printf("\nPRESS ANY BUTTON TO MAIN MENU !!!\n");
	getch();
	system(CLEAR);
	//system("cls");


	}



void del()
{
	int a;
	int say=0;
	system(CLEAR);
//	system("cls");

	if((kp=fopen("kayit.txt","r+"))==NULL)
	{
		printf("can not open\n");
		exit(0);
	}//if

	printf("enter id for deleting>\n");
	scanf("%s",s_id); // searched id for deleting
	i=0;

	while(!feof(kp))
	{
		fscanf(kp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",&ogrenci[i].id,&ogrenci[i].tc,&ogrenci[i].name,&ogrenci[i].s_name,&ogrenci[i].tel,&ogrenci[i].adres);
		strcpy(ogr[i].id,ogrenci[i].id);
		strcpy(ogr[i].tc,ogrenci[i].tc);
		strcpy(ogr[i].name,ogrenci[i].name);
		strcpy(ogr[i].s_name,ogrenci[i].s_name);
		strcpy(ogr[i].tel,ogrenci[i].tel);
		strcpy(ogr[i].adres,ogrenci[i].adres);
		i++;
	}//while
	a=i;
	fclose(kp);
	if((kp=fopen("kayit.txt","w"))==NULL)
	{
	printf("can not open\n");
	}

		for(i=0; i<a; i++)
		{
		if(strcmp(s_id,ogr[i].id)==0) //eðer id no lar eþitse
		{							  //'\0' atýyor
			say++;

		ogr[i].adres[0]='\0';
		ogr[i].id[0]='\0';
		ogr[i].tc[0]='\0';
		ogr[i].tel[0]='\0';
		ogr[i].name[0]='\0';
		ogr[i].s_name[0]='\0';
		ogrenci[i].adres[0]='\0';
		ogrenci[i].id[0]='\0';
		ogrenci[i].tc[0]='\0';
		ogrenci[i].tel[0]='\0';
		ogrenci[i].name[0]='\0';
		ogrenci[i].s_name[0]='\0';
		}//if
		fprintf(kp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ogr[i].id,ogr[i].tc,ogr[i].name,ogr[i].s_name,ogr[i].tel,ogr[i].adres);
		}//for
		printf("deleted...\n");
		if(say==0)
		printf("ID NOT FOUND!!\n");
		fclose(kp);
		printf("\nPRESS ANY BUTTON TO MAIN MENU !!!\n");
		getch();
		system(CLEAR);
	//	system("cls");

} //del()

void upd()
{

	char ch;
	int b;
    system(CLEAR);
	//system("cls");

	printf("enter the student ID for updating>\n");
	scanf("%s",s_id);

	if((kp=fopen("kayit.txt","r+"))==NULL)
	{
		printf("can not open\n");
		exit(0);
	}//if
	i=0;
	while(!feof(kp))
	{
	fscanf(kp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",&ogrenci[i].id,&ogrenci[i].tc,&ogrenci[i].name,&ogrenci[i].s_name,&ogrenci[i].tel,&ogrenci[i].adres);
		strcpy(ogr[i].id,ogrenci[i].id);
		strcpy(ogr[i].tc,ogrenci[i].tc);
		strcpy(ogr[i].name,ogrenci[i].name);
		strcpy(ogr[i].s_name,ogrenci[i].s_name);
		strcpy(ogr[i].tel,ogrenci[i].tel);
		strcpy(ogr[i].adres,ogrenci[i].adres);
		i++;
	} //while (tüm hepsini kopyaladýk)
	b=i;
	fclose(kp);

	for(i=0; i<b; i++)
	{
	if(strcmp(s_id,ogr[i].id)==0)
	{
	say++;
	printf("###################################");
		printf("\nID: %s\n",ogr[i].id);

		printf("TC NO: %s\n",ogr[i].tc);

		printf("NAME: %s\n",ogr[i].name);

		printf("SURNAME: %s\n",ogr[i].s_name);

		printf("TEL NO: %s\n",ogr[i].tel);

		printf("ADDRESSES: %s\n",ogr[i].adres);
		printf("\n");
	}//if strcmp
	}//for

	if(say==0)
	{
	printf("\nNOT FOUND!\n");
	printf("\nPRESS ANY BUTTON BACK TO MAIN MENU !!!\n");
	getch();
	goto end;
	}


	//UPDATE MENU
	printf("what do you want to update\n\n");
	printf("[i]-id\n");
	printf("[t]-tc no\n");
	printf("[n]-name\n");
	printf("[s]-surname\n");
	printf("[o]-tel no\n");
	printf("[a]-addresses\n");
	printf("[q]-quit\n\n");
	printf("chose>>\n");
	ch=getch();

	while(ch!='q' && ch!='Q')
	{

	if((kp=fopen("kayit.txt","w"))==NULL)
	{
	printf("can not open\n");
	} //if


	for(i=0; i<b; i++)
	{
	if(strcmp(s_id,ogr[i].id)==0)
	{
	say++;
	if(ch=='i' || ch=='I')
	{
	printf("enter new id>\n");
	scanf("%s",&ogr[i].id);
	}
	else if(ch=='t' || ch=='T')
	{
	printf("enter new tc>\n");
	scanf("%s",&ogr[i].tc);
	}

	else if(ch=='n' || ch=='N')
	{
	printf("enter new name>\n");
	scanf("%s",&ogr[i].name);
	}
	else if(ch=='s' || ch=='S')
	{
	printf("enter new surname>\n");
	scanf("%s",&ogr[i].s_name);
	}
	else if(ch=='o' || ch=='O')
	{
	printf("enter new tel>\n");
	scanf("%s",&ogr[i].tel);
	}
	else if(ch=='a' || ch=='A')
	{
	printf("enter new addresses(use _ for space character)>\n");
	scanf("%s",&ogr[i].adres);
	}
	}//if strcmp
	}//for

	for(i=0; i<b; i++)
	{
	fprintf(kp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",ogr[i].id,ogr[i].tc,ogr[i].name,ogr[i].s_name,ogr[i].tel,ogr[i].adres);

	}//for

	fclose(kp);
	printf("chose>>\n");
	ch=getch();
	}//while menu seçimi için

	printf("\nPRESS ANY BUTTON TO MAIN MENU !!!\n");
	getch();
	end:
	system(CLEAR);
	//system("cls");
	} // update

