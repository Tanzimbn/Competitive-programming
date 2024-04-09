int mobius[M];
bool sv[M+3];
void cal_mobius()
{
  sv[0]=true; sv[1]=true;
  for(int i=0;i<M;i++) mobius[i]=1;
    mobius[0]=0;mobius[1]=0;
  mobius[2]=-1;
  for(int i=4;i<M;i+=2){
    sv[i]=true;
    mobius[i]*=(i%4)? -1:0;
  }
  for(int i=3;i<M;i+=2){
    if(!sv[i]){
      mobius[i]=-1;
      for(int j=2*i;j<M;j+=i){
        sv[j]=true;
        mobius[j]*=(j%(i*i))? -1:0;
      }
    }
  }
    return;
}
