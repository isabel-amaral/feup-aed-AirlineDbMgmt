## AED_T06_G60 - Airline Database Management

> **2021/2022** - 2nd Year, 1st Semester
> 
> **Course** - AED (Algoritmos e Estruturas de Dados)
> 
> **Project developed by**
> - Isabel Amaral (up202006677)
> - Milena Gouveia (up202008862)
> - Sofia Moura (up201907201)

### Project Description

The purpose of this project was to implement an information management system for an airline company
that must store and allow to effectively manage information related to planes, flights, passengers and luggage.

Most of the main entities that were created for this project - Airport (class Aeroporto), Plane (class Aviao),
Flight (class Voo), Passenger (class Passageiro), Ticket (class Bilhete), Luggage (class Bagagem) etc. -
were managed using STL's linear data structures such as vectors, lists, stacks and queues. One single hierarchical 
data structure, in this case a BST, was used as well to manage all the transportation facilities located near
each airport. We also tried to include as much CRUD basic operations as we could think of in order to 
illustrate the manipulation of every used data structure.

### Implemented Features

Some of the most basic operations were specifically required in the project's description (pt) - [here](./docs/project-description.pdf). 
Bellow there's a listing of the features we're most proud of and some extra ones we came up with by ourselves.

- **Code documentation** - All the implemented classes were documented using doxygen. The complete generated documentation
can be checked in the [docs directory](./docs/output/html). Alternatively just open the [index.html](./docs/output/html/index.html)
in your browser.
- **Interactive Menu** - In order to test and demonstrate the many features developed, we created a simple menu.
Due to lack of time, we didn't manage to cover every single possibility of our code's functionalities, e.g. luggage
transportation, but we still covered a big chunk of it.
- **Mock data** - For an easier visualization of the developed functionalities through the menu, we created a fake
dataset for each of our entities using text files - aeroportos.txt, avioes.txt, voos.txt, passageiros.txt, bilhetes.txt etc.
- **Diversified listings** - The user has the possibility of checking for which flights they have a ticket through their
passenger id and, for each ticket, what luggage he is allowed to bring.
- **Diversified listings with filters** - It's possible for the user to check listings of all the flights offered
by the company or of just some of them, such as the flights which leave from and/or arrive to a specific city determined
by user input or the flights scheduled for specific dates. In a similar way, when looking to check a list of all the 
transportation means near one of the airports, the user also has the possibility to filter by the type of transport 
(Subway, Train or Bus) and provide different sorting criteria (distance - closest to furthest, availability - highest to lowest).
- **Flight cancellation and checking in to a flight** (extra) - We implemented a feature that allows the user to check in
one of their flights and another one that allows to cancel one of the tickets for a flight as long as the check-in hasn't been
done yet.
- **Luggage related fines** (extra) - During check-in, if the user wants to add luggage that exceeds the weight defined as the maximum
weight allowed in their ticket or if they bring hand luggage when it's not allowed by their ticket, a fine is attributed.

### Program Development State

Because we had very little time and this was our biggest project up to the date (higher number of classes and relations between them),
the code is very messy and could be improved in many ways. Also because we made the mistake of waiting until most features were implemented
before implementing the menu and, therefore, have a better idea of whether everything was working well, a lot of bugs were found in the last
couple of days before the final delivery. From the bugs detected, we managed to correct everything. However, there's still the possibility
of having some undetected and that the menu breaks if not used properly. :sweat_smile:

Overall we managed to develop a high number of features, even though the quality of the code isn't the best, and we did good use
of the selected data structures, which was the main goal of the project.

For a more detailed report (pt) check out ppt presentation [here](./docs/presentation.pdf).