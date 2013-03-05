 /* http://kx.com/a/k/connect/c/k20.h */
#define R return
#define O printf
#define Z static
#define WH(x,y) case (x): y; break
#define DO(n,x) {I i=0,_i=(n);for(;i<_i;++i){x;}}
#define BO(x) I c=x->c,t=x->t,r=x->r,*s=x->s,*d=x->d
#define NL O("\n")
#define sO sprintf
#define eO(...) fprintf(stderr,__VA_ARGS__)

typedef int I;typedef double F;typedef char C;typedef C*S;
typedef unsigned char UC;
typedef struct j0{I c,t,r,*s,*d;C h[16];}*J;

#define Iz sizeof(I)
#define Fz sizeof(F)
#define Cz sizeof(C)

I p2(I),l2(I); /*integer power of 2 and log base 2*/
S ts(I),tf(I);I tz(I); /* description of type, %format, size */

/* atom accessors, e.g.	Ji(x)=2 */
#define Ji(x) (*JI(x))
#define Jf(x) (*JF(x))
#define Jc(x) (*JC(x))
#define Js(x) (*JS(x))
/* list accessors, e.g. JF(x)[i]=2.0 */
#define JI(x) ((I*)((x)->d))
#define JF(x) ((F*)((x)->d))
#define JC(x) ((C*)((x)->d))
#define JS(x) ((S*)((x)->d))

#ifdef __cplusplus
extern "C" {
#endif

extern S sp(S); /* symbol from phrase */

/* atom generators, e.g. gi(2),gf(2.0),gc('2'),gs(sp("2")) */
extern J gi(I),gf(F),gc(C),gs(S),gn(void);

/* list generator (t as in 4::), e.g. gtn(-1,9) integer vector */
extern J gtn(I t,I n);

/* phrase (-3=4::) generators, e.g. gp("asdf");C*s;gpn(s,4); */
extern J gp(S),gpn(S,I);

/* error, e.g. if(x->t!=-1)return jerr("need integer vector");*/
extern J jerr(S),gsj(S,J),gnj(I,...),ci(J),jsj(S,J),jap(J*,void*);
extern I cd(J),jd(I),dj(I),scd(I),sdf(I,I(*)(void)),sfn(S,J(*)(S,S),I);

#ifdef  __GNUC__
#define DL(t,f) t f
#else
#define DL(t,f) t __stdcall f  
#endif
extern DL(S,jss)(S); /* call jss '' to init jx */
/* jss is called from j using the jx dll.  eg:    memr xxx xxx xxx    'jx jss *c *c*c' cd 'sum';'i. 3'  */
    
#ifdef __cplusplus 
}
#endif
