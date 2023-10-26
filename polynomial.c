#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to add a term to a polynomial
void addToPolynomial(struct Term** poly, int coefficient, int exponent) {
    struct Term* term = createTerm(coefficient, exponent);
    
    if (*poly == NULL) {
        *poly = term;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = term;
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            addToPolynomial(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            addToPolynomial(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            addToPolynomial(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }

    // Add any remaining terms from poly1 and poly2
    while (poly1 != NULL) {
        addToPolynomial(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addToPolynomial(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL) {
        struct Term* temp = poly2;
        while (temp != NULL) {
            int coefficient = poly1->coefficient * temp->coefficient;
            int exponent = poly1->exponent + temp->exponent;
            addToPolynomial(&result, coefficient, exponent);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Adding terms to the first polynomial (4x^2 + 7x + 1)
    addToPolynomial(&poly1, 6, 2);
    addToPolynomial(&poly1, 7, 1);
    addToPolynomial(&poly1, 3, 0);

    // Adding terms to the second polynomial (4x^3 - 2x^2 + 1)
    addToPolynomial(&poly2, 4, 3);
    addToPolynomial(&poly2, -2, 2);
    addToPolynomial(&poly2, 8, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    struct Term* product = multiplyPolynomials(poly1, poly2);
    printf("Product of polynomials: ");
    displayPolynomial(product);

    // Free memory
    free(sum);
    free(product);

    return 0;
}
