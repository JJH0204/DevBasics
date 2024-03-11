// Exercise_Bitmasks.c
// Use bit masks to manipulate some flags.
#include <stdio.h>
#include <assert.h>

/* Finish initializing the flags */

const short FLAG_ON = 1 << 0;           // 1  (0x01)
const short FLAG_MOVEMENT = 1 << 1;     // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2;  // 4  (0x04)
const short FLAG_ALIVE = 1 << 3;        // 8
const short FLAG_BROKEN = 1 << 4;       // 16
const short FLAG_EDIBLE = 1 << 5;       // 32 (0x20)

int main()
{
    short attributes = (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN);

    /* Set the attributes ON, TRANSPARENT, and BROKEN */
    /* ON, TRANSPARENT, BROKEN 속성을 설정합니다 */

    assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));
    //1 + 4 + 16 = 00001 + 00100 + 10000 = 10101 = 21

    /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
    /* ON 및 ALIVE 속성만 있도록 수정(설정/삭제/전환) */

    attributes = attributes >> 1;
    attributes = attributes & FLAG_ALIVE;
    attributes = attributes | FLAG_ON;

    assert(attributes == (FLAG_ON | FLAG_ALIVE));

    /* Check if the ALIVE flag is set */
    /* ALIVE 플래그가 설정되어 있는지 확인 */
    
    assert(attributes & FLAG_ALIVE);

    /* Check if the BROKEN flag is not set */
    /* BROKEN 플래그가 설정되어 있지 않은지 확인 */

    assert(~attributes & FLAG_BROKEN);

    /* Modify so only the EDIBLE attribute is set */
    /* EDIBLE 속성만 설정되도록 수정 */
    attributes = attributes << 2;
    attributes = attributes & FLAG_EDIBLE;

    assert(attributes == FLAG_EDIBLE);

    printf("Done!");
}

/*assert(assert.h)에 대해
프로그램의 오류를 검출하기 위해 사용되는 매크로 라이브러리
주어진 조건이 거짓(false)일 경우 프로그램을 중단시키고 오류 메시지를 출력
오류 메시지는 assert가 실패한 파일 이름과 라인 번호가 포함되어, 디버깅을 위한 유용한 정보를 제공한다.
프로그램의 논리적 오류를 더 쉽게 찾을 수 있게 된다.
*/