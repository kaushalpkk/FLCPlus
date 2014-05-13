/* running this code will geenrate errors.. modify code based on user-designed system   */

#include "Aria.h"
#include "ariaUtil.h"
#include "myFuzzy.h"                    // basic fuzzy structs
#include "trap1.h"                    // write membership functions here
#include "ruleBase.h"                 // write rules here
#include "misc.h"
#include "fuzzyFy.h"                   // fuzzification functions
#include "inferenceEngine.h"         // inference engine functions
#include "deFuzz.h"                    // defuzzification functions

//fuzzy variables
fireStrength FS_F[3];

firedRules FR_LE_leftWheel;

int main(int argc, char **argv){

		FS_F[0] = getDegreeOfMem(crispFront , &SonarNear);
		FS_F[1] = getDegreeOfMem(crispFront , &SonarGood);
		FS_F[2] = getDegreeOfMem(crispFront , &SonarFar);

		FR_LE_leftWheel =		inferRules(FS_L, FS_F, 3, 3, RB_LE_leftWheel);

		motorLeft = defuzzHeight(FR_LE_leftWheel);

    return 0;
}
