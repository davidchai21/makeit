/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if (!poly1 || !poly2) return poly1 ? poly1 : poly2;
        PolyNode* res = new PolyNode();
        PolyNode* cur = res;
        while (poly1 && poly2) {
            if (poly1->power == poly2->power) {
                int c = poly1->coefficient + poly2->coefficient;
                int power = poly1->power;
                poly1 = poly1->next;
                poly2 = poly2->next;
                if (!c) continue;
                cur->next = new PolyNode(c, power);
            } else if (poly1->power > poly2->power) {
                cur->next = new PolyNode(poly1->coefficient, poly1->power);
                poly1 = poly1->next;
            } else {
                cur->next = new PolyNode(poly2->coefficient, poly2->power);
                poly2 = poly2->next;
            }
            cur = cur->next;
        }
        if (poly1) cur->next = poly1;
        if (poly2) cur->next = poly2;
        cur = res->next;
        res->next = nullptr;
        delete res;
        return cur;
    }
};