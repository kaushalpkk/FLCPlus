// ---------------------------------------------------------------------------------------------
//trapezoids for membership functions: can be used to store rule bases
struct myTrapezoid{
    float low;
    float midLower;
    float midHigher;
    float high;
};

//struct to return firing strengths and respective membership functions
//can be used to store the fired output from fuzzification
typedef struct{
    float firePower;
    myTrapezoid fuzzMem;
}fireStrength;

//struct stores the rules fired obtained from inference engine
typedef struct{
    short totRules;
    fireStrength ruleList[20];
}firedRules;

