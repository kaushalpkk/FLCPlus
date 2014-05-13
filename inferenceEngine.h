/*
function:        get2Dim
input:            shorts
output:            shorts
functioning:    returns the signle dimentional position from a 2D array*/
short get2Dim(short x, short y, short fuzBb){
    short outVal=0;
    outVal = (fuzBb * x) + y;
    return outVal;
}


/*
function:        get3Dim
input:            shorts
output:            shorts
functioning:    returns the signle dimentional position from a 3D array*/
short get3Dim(short x, short y, short z, short fuzA, short fuzB){
    short outVal=0;
    outVal = ((fuzB * y) + z)+(x * fuzA *fuzB);
    return outVal;
}


firedRules inferRules(fireStrength inFuzA[], fireStrength inFuzB[], short sizA, short sizB, const myTrapezoid *ruleBase){

    firedRules outP;
    short oCount=0;
    for(int i=0; i<sizA; i++){
        for(int j=0; j<sizB; j++){
//            printf("i j = %d %d\r\n",i,j);
            if(inFuzA[i].firePower>0 && inFuzB[j].firePower>0){
                outP.ruleList[oCount].firePower = getMin(inFuzA[i].firePower, inFuzB[j].firePower);
                outP.ruleList[oCount].fuzzMem = ruleBase[get2Dim(i, j, sizB)];
//                printf("rule saved %d %d  rule number %d :    %f\r\n",i,j,get2Dim(i, j, sizB),outP.ruleList[oCount].firePower);
                oCount++;
            }    
        }
    }
    outP.totRules = oCount;
    return outP;
}


firedRules inferRules(fireStrength inFuzA[], fireStrength inFuzB[], fireStrength inFuzC[], short sizA, short sizB, short sizC, const myTrapezoid *ruleBase){

    firedRules outP;
    short oCount=0;
    for(int i=0; i<sizA; i++){
        for(int j=0; j<sizB; j++){
            for(int k=0; k<sizC; k++){
//                printf("i j k= %d %d %d (%d)\r\n",i,j,k,get3Dim(i,j,k, sizB, sizC));
                if(inFuzA[i].firePower>0 && inFuzB[j].firePower>0 && inFuzC[k].firePower>0){
                    outP.ruleList[oCount].firePower = getMin(inFuzA[i].firePower, inFuzB[j].firePower, inFuzC[k].firePower);
                    outP.ruleList[oCount].fuzzMem = ruleBase[get3Dim(i, j, k, sizB, sizC)];
//                    printf("rule saved %d %d %d (%d):    %f\n\r",i,j,k,get3Dim(i, j, k, sizB, sizC),outP.ruleList[oCount].firePower);
                    oCount++;
                }    
            }
        }
    }
    outP.totRules = oCount;
    return outP;
}



