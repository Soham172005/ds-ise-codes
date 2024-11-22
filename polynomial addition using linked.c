// Implement univariate Polynomial addition using linked lists. A univariate polynomial should be represented in the decreasing order of its coefficient.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node of the polynomial
typedef struct PolyNode {
    int coeff;       // Coefficient of the term
    int exp;         // Exponent of the term
    struct PolyNode *next; // Pointer to the next term
} PolyNode;

// Function to create a new node
PolyNode* createNode(int coeff, int exp) {
    PolyNode *newNode = (PolyNode *)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in decreasing order of exponent
void insertTerm(PolyNode **poly, int coeff, int exp) {
    PolyNode *newNode = createNode(coeff, exp);
    
    // If the polynomial is empty or the new term has the highest exponent
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    // Find the correct position to insert the new term
    PolyNode *temp = *poly;
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }

    // If terms with the same exponent exist, add their coefficients
    if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff += coeff;
        free(newNode); // No need to create a new node
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPolynomial(PolyNode *poly) {
    PolyNode *temp = poly;
    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        
        if (temp->next != NULL && temp->next->coeff > 0) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
PolyNode* addPolynomials(PolyNode *poly1, PolyNode *poly2) {
    PolyNode *result = NULL;

    // Traverse both polynomials and add terms
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If any terms are left in poly1 or poly2, insert them
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Main function to test the polynomial addition
int main() {
    PolyNode *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    // Inserting terms into the first polynomial (4x^3 + 3x^2 + 2x + 1)
    insertTerm(&poly1, 4, 3);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 1, 0);

    // Inserting terms into the second polynomial (5x^3 + 2x^2 + 3)
    insertTerm(&poly2, 5, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 3, 0);

    // Displaying both polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Adding the polynomials
    sum = addPolynomials(poly1, poly2);

    // Displaying the result
    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    return 0;
}
