# Function Pointers
우리는 포인터를 사용하여 문자 배열을 가리키고 그 문자로 문자열을 만들었습니다. 그런 다음 이러한 포인터를 제어하는 ​​방법을 배웠을 때 상황이 더욱 흥미로워졌습니다. 이제 포인터를 사용하여 함수를 가리키고 호출하는 등 훨씬 더 흥미로운 작업을 수행할 차례입니다.

## 왜 함수를 가리키나요?
당신이 생각할 수 있는 첫 번째 질문은 단순히 이름만으로 함수를 호출할 수 있는데 왜 함수를 호출하기 위해 포인터를 사용하겠는가 하는 것입니다: function(); - 좋은 질문이네요! 이제 배열을 정렬해야 하는 정렬 기능을 상상해 보세요. 때로는 배열 요소를 오름차순이나 내림차순으로 정렬하고 싶을 때가 있습니다. 어떻게 선택하시겠어요? 함수 포인터!

## 함수 포인터 구문
    void (*pf)(int);
나는 당신에게 동의합니다. 이것은 확실히 매우 복잡하거나 그렇게 생각할 수도 있습니다. 해당 코드를 다시 읽고 하나씩 이해해 봅시다. 뒤집어서 읽어보세요. *pf는 함수에 대한 포인터입니다. void는 해당 함수의 반환 유형이고 마지막으로 int는 해당 함수의 인수 유형입니다.

함수 포인터에 포인터를 삽입하고 다시 읽어 보겠습니다.

    char* (*pf)(int*)
다시 말하지만, 
1. *pf는 함수 포인터입니다. 
2. char*는 해당 함수의 반환 유형입니다. 
3. int*는 인수의 유형입니다.

이론으로는 충분합니다. 실제 코드로 손을 더럽혀 봅시다. 다음 예를 참조하세요.

    #include <stdio.h>
    void someFunction(int arg)
    {
        printf("This is someFunction being called and arg is: %d\n", arg);
        printf("Whoops leaving the function now!\n");
    }

    main()
    {
        void (*pf)(int);
        pf = &someFunction;
        printf("We're about to call someFunction() using a pointer!\n");
        (pf)(5);
        printf("Wow that was cool. Back to main now!\n\n");
    }
앞서 이야기한 sort()를 기억하시나요? 우리도 똑같이 할 수 있습니다. 집합을 오름차순으로 정렬하는 대신 다음과 같이 자체 비교 함수를 사용하여 반대의 작업을 수행할 수 있습니다.

    #include <stdio.h>
    #include <stdlib.h> //for qsort()

    int compare(const void* left, const void* right)
    {
        return (*(int*)right - *(int*)left);
        // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
    }
    main()
    {
        int (*cmp) (const void* , const void*);
        cmp = &compare;

        int iarray[] = {1,2,3,4,5,6,7,8,9};
        qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

        int c = 0;
        while (c < sizeof(iarray)/sizeof(*iarray))
        {
            printf("%d \t", iarray[c]);
            c++;
        }
    }

## 함수 포인터를 사용하는 이유는 무엇입니까? 
1. 프로그램 실행 흐름을 유연하게 제어할 수 있다.
   (콜백 함수를 구현하는 등 다양한 프로그래밍 기법을 가능하게 함)
2. 함수 포인터를 매개변수로 받는 함수 정의 가능하다.
   전달되는 인자에 따라 달리 동작하는 함수를 구현할 수 있다.
3. 다양한 상황에서 코드의 재사용성과 유지 보수성을 높인다.