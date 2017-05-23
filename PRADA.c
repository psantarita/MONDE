int m,n,counter;
double minDiff,diff,sum,treshold;
minDiff = 100;
treshold = 0.2;
for(m=0;m<10833;m++)
{
  sum = 0;
  for(n=0;n<=15;n++)
    {
    if(normVec[n]<=treshold)
        {
        diff=normVec[n]-relSigsM[m][n];
        diff *= diff;
        sum += diff;
        }
    }
  if (sum<minDiff)
  {
    minDiff = sum;
    counter = m;
    printf("Counter actualizado: %i \n",counter );
  }
}
printf("Reconstructed Position: %i , %i\n",pointList[counter][0],pointList[counter][1]);
