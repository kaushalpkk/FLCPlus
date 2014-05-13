float defuzzHeight(firedRules inpRules){
    float topPart=0,bottomPart=0;

    for(int i=0; i<inpRules.totRules; i++){
        float centroid = (inpRules.ruleList[i].fuzzMem.midLower + inpRules.ruleList[i].fuzzMem.midHigher)/2;
        topPart = topPart + inpRules.ruleList[i].firePower * centroid;
        bottomPart = bottomPart + inpRules.ruleList[i].firePower;
    }
//    printf("top part: %f    bottom part: %f\r\n",topPart,bottomPart);
     return topPart / bottomPart;
}

float defuzzTest(firedRules inpRules){
    float topPart=0,bottomPart=0;

	for(int i=0; i< inpRules.totRules; i++){
		
	}
     return topPart / bottomPart;
}

float blendBehaviour(float inA, float inB, float finalA, float finalB){
    float totalA = inA * finalA;
    float totalB = inB * finalB;
    
    return ((totalA + totalB)/(inA + inB));
}

float blendBehaviour(float inA, float inB, float inC, float finalA, float finalB, float finalC){
    float totalA = inA * finalA;
    float totalB = inB * finalB;
    float totalC = inC * finalC;
    
    return ((totalA + totalB + totalC)/(inA + inB + inC));
}

float blendBehaviour(float inA, float inB, float inC, float inD, float finalA, float finalB, float finalC, float finalD){
    float totalA = inA * finalA;
    float totalB = inB * finalB;
    float totalC = inC * finalC;
    float totalD = inD * finalD;
    
    return ((totalA + totalB + totalC + totalD)/(inA + inB + inC + inD));
}


