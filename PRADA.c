int j,k,counter;
double minDiff,diff,sum,treshold;
minDiff = 100;
treshold = 0.2;
for(j=0;j<10833;j++)
{
  sum = 0;
  for(k=0;k<=15;k++)
    {
    if(normVec[k]<=treshold)
        {
        diff=normVec[k]-relSigsM[j][k];
        diff *= diff;
        sum += diff;
        }
    }
  if (sum<minDiff)
  {
    minDiff = sum;
    counter = j;
    printf("Counter actualizado: %i \n",counter );
  }
}
printf("Reconstructed Position: %i , %i\n",pointList[counter][0],pointList[counter][1]);
