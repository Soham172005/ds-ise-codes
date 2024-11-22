// Implement univariate Polynomial Multiplication using linked lists. A univariate polynomial should be represented in the decreasing order of its coefficient.

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

// Function to multiply two polynomials
PolyNode* multiplyPolynomials(PolyNode *poly1, PolyNode *poly2) {
    PolyNode *result = NULL;

    // Traverse through the first polynomial
    PolyNode *temp1 = poly1;
    while (temp1 != NULL) {
        // For each term in the first polynomial, multiply it by each term in the second polynomial
        PolyNode *temp2 = poly2;
        while (temp2 != NULL) {
            int newCoeff = temp1->coeff * temp2->coeff;
            int newExp = temp1->exp + temp2->exp;
            insertTerm(&result, newCoeff, newExp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

// Main function to test the polynomial multiplication
int main() {
    PolyNode *poly1 = NULL, *poly2 = NULL, *product = NULL;

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

    // Multiplying the polynomials
    product = multiplyPolynomials(poly1, poly2);

    // Displaying the result
    printf("Product of the polynomials: ");
    displayPolynomial(product);

    return 0;
}
