<img src="utils/1.png" width= 100%>

---

## Introduction

Ce premier module de C++ couvre les bases essentielles de la programmation orientée objet, en se concentrant sur les classes, les objets, et les fonctions membres. Nous apprenons également à manipuler les entrées/sorties via les stdio streams, à initialiser des objets avec des listes d'initialisation, et à utiliser les mots-clés ```static``` et ```const```. Ce module constitue une introduction fondamentale au C++, posant les bases nécessaires pour des études plus approfondies et le développement de projets complexes.

<br>

## Exercice 00 - Megaphone

L'exercice consiste a imprimer sur la sortie standard la ou les chaines de caractères passées en argument du programme.

[Lien ici](https://github.com/aceyzz/CPP00/tree/main/ex00)

### Mon implementation

La fonction ```print_upper_str``` prend une chaîne de caractères en entrée et imprime cette chaîne en majuscules. Elle parcourt chaque caractère de la chaîne et utilise la fonction ```toupper``` pour convertir le caractère en majuscule avant de l'imprimer.

La fonction ```main``` est le point d'entrée du programme. Elle prend deux arguments : ```argc```, qui est le nombre d'arguments de la ligne de commande, et ```argv```, qui est un tableau de chaînes de caractères représentant les arguments de la ligne de commande.

Si au moins un argument est passé à la ligne de commande (autre que le nom du programme lui-même), la fonction main appelle ```print_upper_str``` pour chaque argument et imprime la chaîne en majuscules. Si aucun argument n'est passé, elle imprime la chaîne ```* LOUD AND UNBEARABLE FEEDBACK NOISE *```.

En résumé, ce programme convertit tous les arguments de la ligne de commande en majuscules et les imprime. Si aucun argument n'est fourni, il imprime un message d'erreur spécifique.

<br>


## Exercice 01 - My Awesome Phonebook

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

<br>

## Exercice 02 - L'emploi de mes rêves (Bonus)

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

<br>

## Résultat

<img src="utils/100.png" width= 25%>
