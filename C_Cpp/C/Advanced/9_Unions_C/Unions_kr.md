# Unions
C 유니언은 각각 고유의 메모리를 가진 여러 변수를 포함하는 대신 동일한 변수에 대해 여러 이름을 허용한다는 점을 제외하고는 본질적으로 C 구조와 동일하다. 이 이름들은 메모리를 다른 유형으로 취급할 수 있다. (그리고 조합의 크기는 컴파일러가 부여하기로 결정할 수 있는 가장 큰 유형의 크기가 될 것이다.)

따라서 변수의 메모리를 다른 방식으로 읽을 수 있기를 원한다면, 예를 들어 한 번에 정수 1바이트를 읽는 것과 같이 다음과 같은 것을 가질 수 있습니다:

    union intParts {
    int theInt;
    char bytes[sizeof(int)];
    };
포인터를 캐스팅하지 않고 포인터 산술을 사용하지 않고 각 바이트를 개별적으로 볼 수 있습니다:

    union intParts parts;
    parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // vs

    int theInt = parts.theInt;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));

    // or with array syntax which can be a tiny bit nicer sometimes

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);
이를 구조물과 결합하면 여러 다른 유형을 한 번에 하나씩 저장하는 데 사용할 수 있는 "태그된" 결합을 만들 수 있습니다.

예를 들어, "숫자" 구조를 가질 수 있지만 다음과 같은 것을 사용하고 싶지는 않습니다:

    struct operator {
        int intNum;
        float floatNum;
        int type;
        double doubleNum;
    };
프로그램에 많은 정보가 포함되어 있고 모든 변수에 대해 메모리가 너무 많이 필요하므로 다음을 사용할 수 있습니다:

    struct operator {
        int type;
        union {
        int intNum;
        float floatNum;
        double doubleNum;
        } types;
    };
이와 같이 구조물의 크기는 조합에서 가장 큰 형태(이중)의 크기인 int형의 크기에 불과하다. 큰 이득은 아니지만 8바이트나 16바이트 정도만 이 개념을 유사한 구조에 적용할 수 있다.

use:

    operator op;
    op.type = 0; // int, probably better as an enum or macro constant
    op.types.intNum = 352;
또한 조합의 이름을 지정하지 않으면 조합원은 구조물에서 직접 액세스됩니다:

    struct operator {
        int type;
        union {
            int intNum;
            float floatNum;
            double doubleNum;
        }; // no name!
    };

    operator op;
    op.type = 0; // int
    // intNum is part of the union, but since it's not named you access it directly off the struct itself
    op.intNum = 352;
다른 더 유용한 기능은 동일한 유형의 변수가 항상 여러 개 있고 이름(가독성)과 인덱스(반복하기 쉽도록)를 모두 사용할 수 있는 경우입니다:

    union Coins {
        struct {
            int quarter;
            int dime;
            int nickel;
            int penny;
        }; // 익명 구조체는 익명 공용체와 동일한 방식으로 작동하며 멤버는 외부 컨테이너에 있습니다.
        int coins[4];
    };
그 예에서 당신은 미국에 4개의 (공통) 동전을 포함하는 구조가 있다는 것을 알 수 있다.

유니언은 변수가 동일한 메모리를 공유하도록 만들기 때문에 코인 배열은 구조의 각 int와 일치한다(순서대로):

    union Coins change;
    for(int i = 0; i < sizeof(change) / sizeof(int); ++i)
    {
        scanf("%i", change.coins + i); // 잘못된 코드입니다! 입력은 항상 주의해야 합니다.
    }
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
        change.quarter, change.dime, change.nickel, change.penny);