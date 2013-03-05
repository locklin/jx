#include "j.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void*P;
extern DL(I,JInit)(void);
/* return 0 or error code unless noted */
extern DL(I,JFree)(I h);
extern DL(I,JDo)(I h,S s); /* execute the j sentence s */
extern DL(I,JGetM)(I h,S n,I*t,I*r,I**s,P d); /* handle,name,type,rank,shape,data */
extern DL(I,JSetM)(I h,S n,I*t,I*r,I**s,P d);
extern DL(S,JGetA)(I h,I,S); /* returns 0 for error or pointer to 3!:1 format */
extern DL(I,JSetA)(I,I,S,I,P);

/* types see doc for 3!:0 at system/extras/help/dictionary/dx003.htm */
S tss[21]={"boolean","literal","integer","floating point","complex","boxed", 
 /*6*/"extended integer","rational","256","512",
 /*10*/"sparse boolean","sparse literal","sparse integer",
 /*13*/"sparse floating point","sparse complex","sparse boxed", 
 /*16*/"symbol","unicode", /*end of j defined types*/ 
 /*18*/"nulltype","jx"/*two additional types for jx*/ ,"out-of-bounds" }, 
  tsf[20]={"%d","%c","%d","%f","","","","","256","512","","","","","","", 
           "sym %s","uni %s","null %d","jx %d"}; 
I tsz[20]={Cz,Cz,Iz,Fz,0,0,0,0,256,512,0,0,0,0,0,0,Cz,0,Cz,0},
  tsi[20]={1, 2, 3, 4, 5, 0,6,7,17,18,19,20,21,22,16, 7, 8, 9,10};
p2(x){R 1<<x;} l2(x){DO(32,if(p2(i)>=x)R i;)}
#define TYLU(x,y) x t##y(t){R ts##y[l2(t)];}
TYLU(S,s) TYLU(I,z) TYLU(I,i) TYLU(S,f) 
#define NL O("\n")
#define sO sprintf
#define eO(...) fprintf(stderr,__VA_ARGS__)
#define LC  "effb1ae"
I j_,n_;
Z jf(){R JFree(j_);} Z jdo(S s){R JDo(j_,s);} 
#define nm(j) ((j)->h)
#define jX(x) {R J##x##etM(j_,nm(j),&j->t,&j->r,&j->s,(P*)&j->d);}
jg(J j)jX(G) js(J j)jX(S)

/*the api*/
cd(J j){if(j->c--==0){C b[99];sO(b,"4!:55<'%s'",nm(j));jdo(b);free(j);}R j->c;}
J ci(J j){j->c++;R j;}
/*atom generators*/
Z nz(t,r,s)I*s;{I z=1;DO(r,z*=s[i]);R z;}
Z J nw(){I z=sizeof(struct j0);J j=malloc(z);
 memset(j,0,z);j->c++;sO(j->h,"jx%08d_jx_",n_++);R j;
} 
Z J gx(t,r,s)I*s; {J j=nw();j->d=malloc(nz(t,r,s)*tz(t));}
//J gi(I x){J j=gx(4,1,1);Ji((J)j)=x;nm(j);R j;}
#define Ci 4
#define Cf 8
typedef I Ti;typedef F Tf;
#define assert(x) {I y;(x)||(eO("assert: %s\n",#x),y=*(I*)0);}
#define gt(t) \
 J g##t(T##t x){I y=C##t;J j=nw();JSetM(j_,nm(j),&y,0,0,(P*)&x);R j;}
gt(i) gt(f)  J nul,ero,tmp;
J jsj(S s,J j)
{if(*s==0&&j==0){j_=JInit();j_||eO("! JInit");
  jdo("jxl=:>18!:3<'jx'");
  jdo("'jx 15!:0 jxl=:>18!:3<'jx'");
  jdo("jdir_jx_=:_12 }. 1!:45''");
  n_=0;tmp=nw();nul=nw();ero=nw();nul->t=ero->t=p2(18);
  R ci(ero);}
 {C ss[99],b[99];
  if(j)
  {assert(j->r==1);
   if(j->s[0]==1)sO(b,"%s (0{%s)",s,nm(j));
   else sO(b,"(0{%s) %s (1{%s)",nm(j),s,nm(j));
  }else sO(b,"%s",s);
  {J x=nw();sO(ss,"%s=:%s",nm(x),b);
   {I e;if(e=jdo(ss))
    {I f;C g[99];sO(g,"%s=:>%d{9!:8''",tmp->h,e-1);
     if(f=jdo(g))R eO("! jdo->%d then jdo(%s)->%d  post err\n",e,f,g),(J)1;
     if(f=jg(tmp))R eO("! %d=jg(0x%x) post err\n",e,tmp),(J)1;
     ero->d=tmp->d;R ero;
   }}
   jg(x);R x;
}}}
J(*fns[26])(S,S);
DL(S,jss)(S x)//,S y)
{if(!x||!*x)jsj("",0); /* JDo(j_,x); k=fns[*x-'a'](x,y); R nm(j);*/
}
sfn(S s,J(*f)(S,S),I n){fns[*s-'a']=f;}
