# Overview

Notes and various algorithms as implemented in the C programming language

# References

* [Data Structures and Algorithms - tutorialspoint.com](https://www.tutorialspoint.com/data_structures_algorithms/index.htm)

# Books

* [Algorithms Illuminated](https://www.amazon.com/Algorithms-Illuminated-Part-1-Basics-ebook/dp/B075YQP38X) refer also to the companion YouTube series below.
* [Mathematics for Computer Science](https://courses.csail.mit.edu/6.042/spring17/mcs.pdf) - online book in pdf format.  There is an associated [MIT Open Courseware](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-042j-mathematics-for-computer-science-fall-2010/) class on this

# YouTube Videos

* [Algorithms Illuminated Series](https://www.youtube.com/watch?v=yRM3sc57q0c&list=PLXFMmlk03Dt7Q0xr1PIAriY5623cKiH7V&t=41s&index=1) - Corresponds to the Algorithms Illuminated books series.

# Concepts and Terminology


## Asymptotic Analysis

From: [tutorialspoint - Asymptotic Analysis](https://www.tutorialspoint.com/data_structures_algorithms/asymptotic_analysis.htm)

**Important Note:** the information in this section is quoting directly from [tutorialspoint - Asymptotic Analysis](https://www.tutorialspoint.com/data_structures_algorithms/asymptotic_analysis.htm).  Please refer to this site for more details, including graphs.

Asymptotic analysis refers to computing the running time of any operation in mathematical units of computation. For example, the running time of one operation is computed as f(n) and may be for another operation it is computed as g(n2). This means the first operation running time will increase linearly with the increase in n and the running time of the second operation will increase exponentially when n increases. Similarly, the running time of both operations will be nearly the same if n is significantly small.

Usually, the time required by an algorithm falls under three types −

* **Best Case** − Minimum time required for program execution.
* **Average Case** − Average time required for program execution.
* **Worst Case** − Maximum time required for program execution.

### Asymptotic Notations
Following are the commonly used asymptotic notations to calculate the running time complexity of an algorithm.

* **Ο Notation**
* **Ω Notation**
* **θ Notation**

### Big Oh Notation, Ο

The notation Ο(n) is the formal way to express the upper bound of an algorithm's running time. It measures the worst case time complexity or the longest amount of time an algorithm can possibly take to complete.

For example, for a function f(n)

Ο(f(n)) = { g(n) : there exists c > 0 and n0 such that f(n) ≤ c.g(n) for all n > n0. }

### Theta Notation, θ

The notation θ(n) is the formal way to express both the lower bound and the upper bound of an algorithm's running time.

For example, for a function f(n)

Ο(f(n)) = { g(n) : there exists c > 0 and n0 such that f(n) ≤ c.g(n) for all n > n0. }

### Common Asymptotic Notations

Following is a list of some common asymptotic notations −

Type         | Expression
-------------|-------------
constant     | Ο(1)
logarithmic  | Ο(log n)
linear       | Ο(n)
n log n      | Ο(n log n)
quadratic    | Ο(n2)
cubic        | Ο(n3)
polynomial   | nΟ(1)
exponential  | 2Ο(n)
