/*  The Journey of the Little Cow  —  pure‑C version  */
/*  compile:  gcc -std=c17 -O2 cow.c -lm             */

#include <stdio.h>
#include <math.h>

#define EPS 1e-8L          /* ค่าความคลาดเคลื่อนสำหรับเปรียบเทียบเลขทศนิยม */

int main(void)
{
    int j, d;
    long double K;         /* ค่าเกณฑ์สารอาหาร (หน่วยเดียวกับโจทย์) */

    /* ---------- 1. รับข้อมูล ---------- */
    if (scanf("%d %Lf", &j, &K) != 2) return 0;
    if (scanf("%d", &d) != 1) return 0;

    long double P = powl(10.0L, j);   /* P = 10^j  ใช้ long double เพิ่มความแม่น */

    int milk = 0, promax = 0;         /* ตัวนับผลลัพธ์ตามโจทย์ */
    long double nutrientSum = 0.0L;   /* สะสมสารอาหารรวม */

    /* ---------- 2. ประมวลผลทีละวัน ---------- */
    for (int i = 0; i < d; ++i) {
        long long seed;               /* เม็ดอาหารของวัน i (จำนวนเต็ม) */
        scanf("%lld", &seed);

        long double nutrient = (long double)seed * P;
        nutrientSum += nutrient;

        if (nutrient + EPS >= K)      /* มากกว่าหรือเท่าค่า K ภายในช่วง EPS */
            ++milk;

        if (fabsl(nutrient - K) <= EPS) /* เท่าพอดี (±EPS) */
            ++promax;
    }

    /* ---------- 3. แสดงผล ---------- */
    printf("Milk : %d\n",     milk);
    printf("ProMax Milk : %d\n", promax);
    printf("Nutrient : %.17Lf\n", nutrientSum);

    return 0;
}
