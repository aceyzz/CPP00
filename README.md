<img src="git_utils/banner.png" width= 100%>

<br>

---

<br>

<details>
<summary>FRENCH VERSION</summary>

## Introduction

Ce premier module de C++ couvre les bases essentielles de la programmation orientée objet, en se concentrant sur les classes, les objets, et les fonctions membres. Nous apprenons également à manipuler les entrées/sorties via les stdio streams, à initialiser des objets avec des listes d'initialisation, et à utiliser les mots-clés ```static``` et ```const```. Ce module constitue une introduction fondamentale au C++, posant les bases nécessaires pour des études plus approfondies et le développement de projets complexes.

<br>

## Exercice 00 - Megaphone

<details>
  <summary>Afficher/Masquer</summary>

L'exercice consiste a imprimer sur la sortie standard la ou les chaines de caractères passées en argument du programme.

[Lien ici](https://github.com/aceyzz/CPP00/tree/main/ex00)

### Mon implementation

La fonction ```print_upper_str``` prend une chaîne de caractères en entrée et imprime cette chaîne en majuscules. Elle parcourt chaque caractère de la chaîne et utilise la fonction ```toupper``` pour convertir le caractère en majuscule avant de l'imprimer.

La fonction ```main``` est le point d'entrée du programme. Elle prend deux arguments : ```argc```, qui est le nombre d'arguments de la ligne de commande, et ```argv```, qui est un tableau de chaînes de caractères représentant les arguments de la ligne de commande.

Si au moins un argument est passé à la ligne de commande (autre que le nom du programme lui-même), la fonction main appelle ```print_upper_str``` pour chaque argument et imprime la chaîne en majuscules. Si aucun argument n'est passé, elle imprime la chaîne ```* LOUD AND UNBEARABLE FEEDBACK NOISE *```.

En résumé, ce programme convertit tous les arguments de la ligne de commande en majuscules et les imprime. Si aucun argument n'est fourni, il imprime un message d'erreur spécifique.

</details>

<br>


## Exercice 01 - My Awesome Phonebook

<details>
  <summary>Afficher/Masquer</summary>

L'exercice consiste à créer un Phonebook de 8 contacts, en implementant 3 fonctionnalités : 

- ```ADD```: Ajouter un contact
- ```SEARCH```: Recherchez un contact a un index précis
- ```EXIT```: Quitte le programme

<br>

Le Phonebook doit pouvoir contenir, pour chaque contact, les champs suivants : 

- First name
- Last name
- Nick name
- Phone number
- Darkest secret

<br>

L'affichage du phonebook doit avoir un formattage précis (voir sujet).

[Lien ici](https://github.com/aceyzz/CPP00/tree/main/ex01)

### Mon implémentation

```cleanInput``` : Nettoie une chaîne de caractères en supprimant les espaces en début et en fin de chaîne.

```is_digit``` : Vérifie si une chaîne de caractères est composée uniquement de chiffres.

```isEmptyLine``` : Vérifie si une chaîne de caractères est vide ou contient uniquement des espaces.

```validateInput``` et ```validateInputNbr``` : Demandent à l'utilisateur de saisir une chaîne de caractères et vérifient si l'entrée est valide. Si l'entrée n'est pas valide, un message d'erreur est affiché et l'utilisateur est invité à saisir à nouveau.

```shiftContact``` : Déplace tous les contacts d'un index vers le haut pour faire de la place à un nouveau contact, afin que les nouveaux contacts soient toujours a l'index premier.

```addContact``` : Demande à l'utilisateur de saisir les informations d'un nouveau contact et ajoute ce contact au carnet d'adresses.

```drawHeader``` : Affiche l'en-tête du tableau de contacts.

```printContacts``` : Affiche tous les contacts dans un format de tableau.

```askIndex``` : Demande à l'utilisateur de saisir l'index d'un contact à rechercher et affiche les informations de ce contact.

```searchContact``` : Affiche tous les contacts et demande à l'utilisateur de choisir un contact à rechercher.

```main```: le point d'entrée du programme. Elle crée un carnet d'adresses et entre dans une boucle qui attend les commandes de l'utilisateur. L'utilisateur peut ajouter un contact avec la commande ```ADD```, rechercher un contact avec la commande ```SEARCH``` ou quitter le programme avec la commande ```EXIT```.

</details>

<br>

## Exercice 02 - L'emploi de mes rêves (Bonus)

<details>
  <summary>Afficher/Masquer</summary>

Dans cet exercice, le sujet nous fournit les fichiers contenant une classe ```Account```, un programme de test et un fichier ```.log``` contenant l'output attendu. Notre objectif est de recréer les fonctions membres de la classe afin d'obtenir le même output que le fichier ```.log```.

[Lien ici](https://github.com/aceyzz/CPP00/tree/main/ex02)

### Mon implémentation

Variables statiques : ```g_index```, ```_nbAccounts```, ```_totalAmount```, ```_totalNbDeposits```, ```_totalNbWithdrawals```. Ces variables sont utilisées pour suivre l'index du compte, le nombre total de comptes, le montant total sur tous les comptes, le nombre total de dépôts et de retraits.

```Account::Account(int initial_deposit)```: Ce constructeur initialise un compte avec un dépôt initial, met à jour les variables statiques appropriées et affiche un message indiquant que le compte a été créé.

```Account::~Account(void)```: Ce destructeur affiche un message indiquant que le compte a été fermé.

```_displayTimestamp(void)```: Cette méthode privée statique affiche l'heure actuelle dans le format ```[YYYYMMDD_HHMMSS]```.

```getNbAccounts(void)```, ```getTotalAmount(void)```, ```getNbDeposits(void)```, ```getNbWithdrawals(void)```, ```displayAccountsInfos(void)```: Ces méthodes publiques statiques renvoient respectivement le nombre total de comptes, le montant total sur tous les comptes, le nombre total de dépôts, le nombre total de retraits et affichent les informations sur tous les comptes.

```makeDeposit(int deposit)```, ```makeWithdrawal(int withdrawal)```, ```checkAmount(void) const```, ```displayStatus(void) const```: Ces méthodes publiques non-statiques permettent de déposer de l'argent sur le compte, de retirer de l'argent du compte, de vérifier le montant actuel sur le compte et d'afficher le statut actuel du compte, respectivement.

Dans la méthode ```makeDeposit(int deposit)```, le montant du dépôt est ajouté au solde du compte et les variables statiques appropriées sont mises à jour. Un message est affiché pour indiquer que le dépôt a été effectué.

Dans la méthode ```makeWithdrawal(int withdrawal)```, si le retrait est possible (c'est-à-dire si le solde du compte est suffisant et si le montant du retrait est positif), le montant du retrait est soustrait du solde du compte et les variables statiques appropriées sont mises à jour. Un message est affiché pour indiquer que le retrait a été effectué. Si le retrait n'est pas possible, un message est affiché pour indiquer que le retrait a été refusé.

Le meilleur moyen de checker si l'output de mon implémenation et celui donné dans l'énoncé est de faire une redirection de la sortie de mon programme vers un nouveau fichier.log (```./programme > fichier.log```), puis de faire une commande ```diff``` en ignorant bien entendu les timestamps (qui seront systematiquement différent de l'exemple) et l'ordre dans lequel les destructors sont appelés.

</details>

<br>

## Résultat

<img src="git_utils/100.png" width= 25%>

</details>

<br>

---

<br>

<details>
<summary>ENGLISH VERSION</summary>

## Introduction

This first C++ module covers the essential basics of object-oriented programming, focusing on classes, objects, and member functions. We also learn how to handle input/output via stdio streams, initialize objects with initializer lists, and use the keywords ```static``` and ```const```. This module serves as a fundamental introduction to C++, laying the groundwork for further studies and the development of complex projects.

<br>

## Exercise 00 - Megaphone

<details>
	<summary>Show/Hide</summary>

The exercise consists of printing to the standard output the string(s) passed as arguments to the program.

[Link here](https://github.com/aceyzz/CPP00/tree/main/ex00)

### My Implementation

The function ```print_upper_str``` takes a string as input and prints it in uppercase. It iterates through each character of the string and uses the ```toupper``` function to convert the character to uppercase before printing it.

The ```main``` function is the program's entry point. It takes two arguments: ```argc```, which is the number of command-line arguments, and ```argv```, which is an array of strings representing the command-line arguments.

If at least one argument is passed to the command line (other than the program's name itself), the main function calls ```print_upper_str``` for each argument and prints the string in uppercase. If no arguments are passed, it prints the string ```* LOUD AND UNBEARABLE FEEDBACK NOISE *```.

In summary, this program converts all command-line arguments to uppercase and prints them. If no arguments are provided, it prints a specific error message.

</details>

<br>

## Exercise 01 - My Awesome Phonebook

<details>
	<summary>Show/Hide</summary>

The exercise consists of creating a Phonebook with 8 contacts, implementing 3 functionalities:

- ```ADD```: Add a contact
- ```SEARCH```: Search for a contact at a specific index
- ```EXIT```: Exit the program

<br>

The Phonebook must be able to store, for each contact, the following fields:

- First name
- Last name
- Nickname
- Phone number
- Darkest secret

<br>

The Phonebook display must follow a precise formatting (see subject).

[Link here](https://github.com/aceyzz/CPP00/tree/main/ex01)

### My Implementation

```cleanInput```: Cleans a string by removing leading and trailing spaces.

```is_digit```: Checks if a string consists only of digits.

```isEmptyLine```: Checks if a string is empty or contains only spaces.

```validateInput``` and ```validateInputNbr```: Prompt the user to enter a string and validate the input. If the input is invalid, an error message is displayed, and the user is prompted to enter it again.

```shiftContact```: Shifts all contacts up by one index to make room for a new contact, ensuring new contacts are always at the first index.

```addContact```: Prompts the user to enter the details of a new contact and adds it to the address book.

```drawHeader```: Displays the header of the contact table.

```printContacts```: Displays all contacts in a table format.

```askIndex```: Prompts the user to enter the index of a contact to search for and displays the contact's details.

```searchContact```: Displays all contacts and prompts the user to choose a contact to search for.

```main```: The program's entry point. It creates an address book and enters a loop waiting for user commands. The user can add a contact with the ```ADD``` command, search for a contact with the ```SEARCH``` command, or exit the program with the ```EXIT``` command.

</details>

<br>

## Exercise 02 - My Dream Job (Bonus)

<details>
	<summary>Show/Hide</summary>

In this exercise, the subject provides files containing a class ```Account```, a test program, and a ```.log``` file with the expected output. Our goal is to recreate the member functions of the class to produce the same output as the ```.log``` file.

[Link here](https://github.com/aceyzz/CPP00/tree/main/ex02)

### My Implementation

Static variables: ```g_index```, ```_nbAccounts```, ```_totalAmount```, ```_totalNbDeposits```, ```_totalNbWithdrawals```. These variables are used to track the account index, the total number of accounts, the total amount across all accounts, the total number of deposits, and the total number of withdrawals.

```Account::Account(int initial_deposit)```: This constructor initializes an account with an initial deposit, updates the appropriate static variables, and displays a message indicating that the account has been created.

```Account::~Account(void)```: This destructor displays a message indicating that the account has been closed.

```_displayTimestamp(void)```: This private static method displays the current time in the format ```[YYYYMMDD_HHMMSS]```.

```getNbAccounts(void)```, ```getTotalAmount(void)```, ```getNbDeposits(void)```, ```getNbWithdrawals(void)```, ```displayAccountsInfos(void)```: These public static methods respectively return the total number of accounts, the total amount across all accounts, the total number of deposits, the total number of withdrawals, and display information about all accounts.

```makeDeposit(int deposit)```, ```makeWithdrawal(int withdrawal)```, ```checkAmount(void) const```, ```displayStatus(void) const```: These public non-static methods allow depositing money into the account, withdrawing money from the account, checking the current account balance, and displaying the current account status, respectively.

In the ```makeDeposit(int deposit)``` method, the deposit amount is added to the account balance, and the appropriate static variables are updated. A message is displayed to indicate that the deposit has been made.

In the ```makeWithdrawal(int withdrawal)``` method, if the withdrawal is possible (i.e., the account balance is sufficient and the withdrawal amount is positive), the withdrawal amount is subtracted from the account balance, and the appropriate static variables are updated. A message is displayed to indicate that the withdrawal has been made. If the withdrawal is not possible, a message is displayed to indicate that the withdrawal was refused.

The best way to check if the output of my implementation matches the one provided in the subject is to redirect the program's output to a new ```.log``` file (```./program > file.log```), then use the ```diff``` command while ignoring timestamps (which will always differ from the example) and the order in which destructors are called.

</details>

<br>

## Result

<img src="git_utils/100.png" width= 25%>

</details>