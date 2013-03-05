#include "j.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) x>y?x:y

S sps[]={" ","\n","\n","---\n",0};
show(J x)
{BO(x),sx[9],j;sx[0]=1;DO(r,sx[i+1]=sx[i]*s[i]);
 O("%s (%d),rank %d,shape",ts(t),t,r);DO(r,O(" %d",s[i]));
 O(", data 0x%x:",d);DO(8,O(" %02x",((UC*)d)[i]));NL;
 for(j=0;j<sx[r];j++)
#define WHZ(y) WH(y##z,O(tf(t),J##y(x)[j]))
 {switch(tz(t)){WHZ(C);WHZ(I);WHZ(F);}
  DO(r,(j%sx[i]-sx[i]+1)||O(sps[i]));}NL;
}

sum(int*x,int n){int z=0,i=0;for(;i<n;i++)z+=x[i];return z;}
main(){C b[99];
 cd(jsj("",0));
 while(O("j>"),fgets(b,99,stdin))
 {J r=jsj(b,0);
  if(18==l2(r->t)&&NULL!=r->d)eO("! %s\n",r->d);
  else show(r);
  cd(r);
}NL;}
