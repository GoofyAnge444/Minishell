#!/bin/bash

# Script de tests pour minishell
# Auteur: Assistant IA, ✮⋆˙Claude✧*。 if you will
# Version: 1.0

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Variables globales
MINISHELL_PATH="./minishell"
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
TEST_FILES_DIR="./test_files"
CUSTOM_TEST_FILE=""

# Fonction pour afficher les résultats
print_header() {
    echo -e "${PURPLE}=====================================${NC}"
    echo -e "${PURPLE}           TESTS MINISHELL           ${NC}"
    echo -e "${PURPLE}=====================================${NC}"
    echo ""
}

print_section() {
    echo -e "\n${BLUE}>>> $1 <<<${NC}"
    echo "-----------------------------------"
}

print_test_result() {
    local test_name="$1"
    local expected="$2"
    local actual="$3"
    local status="$4"
	local cmd="$5"
    
    ((TOTAL_TESTS++))
    
    if [ "$status" = "PASS" ]; then
        echo -e "${GREEN}✓ PASS${NC}: $test_name"
        ((PASSED_TESTS++))
    else
        echo -e "${RED}✗ FAIL${NC}: $test_name"
        echo -e "  ${YELLOW}cmd: ${NC} $cmd"
        echo -e "  ${YELLOW}Attendu:${NC} $expected"
        echo -e "  ${YELLOW}Obtenu: ${NC} $actual"
        ((FAILED_TESTS++))
    fi
}

# Fonction pour exécuter un test
run_test() {
    local cmd="$1"
    local test_name="$2"
    
    # Exécution avec bash
    bash_output=$(bash -c "$cmd" 2>&1)
    bash_exit=$?
    
    # Exécution avec minishell
    minishell_output=$(echo "$cmd" | $MINISHELL_PATH 2>&1 | grep -v "mishell$ ")
    minishell_exit=$?
    
    # Comparaison des sorties (en ignorant les espaces en début/fin)
    bash_clean=$(echo "$bash_output" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
    minishell_clean=$(echo "$minishell_output" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
    
    if [ "$bash_clean" = "$minishell_clean" ] && [ "$bash_exit" = "$minishell_exit" ]; then
        print_test_result "$test_name" "$bash_clean" "$minishell_clean" "PASS"
    else
        print_test_result "$test_name" "$bash_clean (exit: $bash_exit)" "$minishell_clean (exit: $minishell_exit)" "FAIL" "$cmd"
    fi
}

# Fonction pour créer les fichiers de test
setup_test_files() {
    mkdir -p "$TEST_FILES_DIR"
    echo "Hello World" > "$TEST_FILES_DIR/test1.txt"
    echo -e "line1\nline2\nline3" > "$TEST_FILES_DIR/test2.txt"
    echo "Test content" > "$TEST_FILES_DIR/readable.txt"
    chmod 644 "$TEST_FILES_DIR/readable.txt"
    
    # Créer un fichier non-lisible
    echo "Secret content" > "$TEST_FILES_DIR/unreadable.txt"
    chmod 000 "$TEST_FILES_DIR/unreadable.txt"
    
    # Créer un répertoire pour les tests
    mkdir -p "$TEST_FILES_DIR/testdir"
    echo "File in directory" > "$TEST_FILES_DIR/testdir/file.txt"
}

# Fonction pour nettoyer les fichiers de test
cleanup_test_files() {
    chmod 644 "$TEST_FILES_DIR/unreadable.txt" 2>/dev/null
    rm -rf "$TEST_FILES_DIR"
}

# Tests des builtins
test_builtins() {
    print_section "TESTS DES BUILTINS"
    
    # Tests echo
    run_test "echo Hello World" "echo - message simple"
    run_test "echo -n Hello" "echo -n - sans nouvelle ligne"
    run_test "echo" "echo - sans arguments"
    run_test "echo -n" "echo -n - sans arguments"
    run_test "echo -nnnn Hello" "echo - options multiples -n"
    
    # Tests pwd
    run_test "pwd" "pwd - répertoire courant"
    
    # Tests env (test basique)
    export TEST_VAR="test_value"
    run_test "env | grep TEST_VAR" "env - variable d'environnement"
    
    # Tests cd et pwd combinés
    current_dir=$(pwd)
    mkdir -p /tmp/minishell_test
    run_test "cd /tmp/minishell_test && pwd" "cd - changement de répertoire"
    cd "$current_dir"
    rm -rf /tmp/minishell_test
    
    # Tests exit
    echo -e "exit 42\n" | $MINISHELL_PATH > /dev/null 2>&1
    exit_code=$?
    if [ $exit_code -eq 42 ]; then
        print_test_result "exit - code de sortie 42" "42" "$exit_code" "PASS"
    else
        print_test_result "exit - code de sortie 42" "42" "$exit_code" "FAIL"
    fi
}

# Tests des variables d'environnement
test_environment_variables() {
    print_section "TESTS DES VARIABLES D'ENVIRONNEMENT"
    
    export TEST_VAR="hello"
    run_test "echo \$TEST_VAR" "Variable d'environnement simple"
    run_test "echo \$USER" "Variable USER"
    run_test "echo \$HOME" "Variable HOME"
    run_test "echo \$PWD" "Variable PWD"
    run_test "echo \$UNDEFINED_VAR" "Variable non définie"
    run_test "echo \$?" "Code de sortie précédent"
}

# Tests des quotes
test_quotes() {
    print_section "TESTS DES QUOTES"
    
    run_test "echo 'Hello World'" "Quotes simples"
    run_test "echo \"Hello World\"" "Quotes doubles"
    run_test "echo 'Hello \"World\"'" "Quotes simples avec doubles à l'intérieur"
    run_test "echo \"Hello 'World'\"" "Quotes doubles avec simples à l'intérieur"
    run_test "echo \"Hello \$USER\"" "Expansion de variable dans quotes doubles"
    run_test "echo 'Hello \$USER'" "Pas d'expansion dans quotes simples"
    run_test "echo Hello' 'World" "Quotes partielles"
}

# Tests des redirections
test_redirections() {
    print_section "TESTS DES REDIRECTIONS"
    
    setup_test_files
    
    # Redirection de sortie
    run_test "echo 'test' > $TEST_FILES_DIR/output.txt && cat $TEST_FILES_DIR/output.txt" "Redirection sortie >"
    run_test "echo 'line1' > $TEST_FILES_DIR/append.txt && echo 'line2' >> $TEST_FILES_DIR/append.txt && cat $TEST_FILES_DIR/append.txt" "Redirection append >>"
    
    # Redirection d'entrée
    run_test "cat < $TEST_FILES_DIR/test1.txt" "Redirection entrée <"
    
    # Here document (si supporté)
    run_test "cat << EOF
Hello
World
EOF" "Here document <<"
    
    cleanup_test_files
}

# Tests des pipes
test_pipes() {
    print_section "TESTS DES PIPES"
    
    run_test "echo 'Hello World' | cat" "Pipe simple"
    run_test "echo 'Hello World' | grep Hello" "Pipe avec grep"
    run_test "ls /bin | head -5" "Pipe avec ls et head"
    run_test "echo 'line1\nline2\nline3' | wc -l" "Pipe avec wc"
    run_test "echo 'Hello World' | cat | cat" "Pipes multiples"
    run_test "ls /bin | grep sh | head -3" "Trois pipes"
}

# Tests des commandes externes
test_external_commands() {
    print_section "TESTS DES COMMANDES EXTERNES"
    
    run_test "ls /" "ls - listage répertoire"
    run_test "cat /etc/passwd | head -1" "cat - lecture fichier"
    run_test "grep root /etc/passwd | head -1" "grep - recherche pattern"
    run_test "wc -l /etc/passwd" "wc - comptage lignes"
    run_test "head -5 /etc/passwd" "head - premières lignes"
    run_test "tail -5 /etc/passwd" "tail - dernières lignes"
}

# Tests de gestion d'erreurs
test_error_handling() {
    print_section "TESTS DE GESTION D'ERREURS"
    
    run_test "cat /nonexistent_file" "Fichier inexistant"
    run_test "cd /nonexistent_directory" "cd vers répertoire inexistant"
    run_test "/nonexistent_command" "Commande inexistante"
    run_test "echo test > /root/forbidden" "Écriture interdite"
}

# Tests de syntaxe complexe
test_complex_syntax() {
    print_section "TESTS DE SYNTAXE COMPLEXE"
    
    run_test "echo \"Hello \$USER, you are in \$PWD\"" "Variables multiples dans quotes"
    run_test "echo 'test' | cat | grep test" "Pipes multiples avec grep"
    run_test "ls -la | grep '^d' | wc -l" "Comptage répertoires"
}

# Tests des espaces et caractères spéciaux
test_whitespace_and_special() {
    print_section "TESTS ESPACES ET CARACTÈRES SPÉCIAUX"
    
    run_test "echo    hello    world" "Espaces multiples"
    run_test "echo 'hello   world'" "Espaces dans quotes"
    run_test "echo \$" "Dollar échappé"
}

# Tests personnalisés depuis fichier
test_custom_from_file() {
    if [ -z "$CUSTOM_TEST_FILE" ] || [ ! -f "$CUSTOM_TEST_FILE" ]; then
        return
    fi
    
    print_section "TESTS PERSONNALISÉS DEPUIS FICHIER: $CUSTOM_TEST_FILE"
    
    local line_number=1
    while IFS= read -r line || [ -n "$line" ]; do
        # Ignorer les lignes vides et les commentaires
        if [[ -z "$line" ]] || [[ "$line" =~ ^[[:space:]]*# ]]; then
            ((line_number++))
            continue
        fi
        
        # Nettoyer la ligne (supprimer espaces début/fin)
        line=$(echo "$line" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')
        
        if [ -n "$line" ]; then
            run_test "$line" "Ligne $line_number: $line"
        fi
        
        ((line_number++))
    done < "$CUSTOM_TEST_FILE"
}

# Afficher l'aide
show_help() {
    echo "Usage: $0 [OPTIONS]"
    echo ""
    echo "Options:"
    echo "  -f, --file FILE    Exécuter les tests depuis un fichier texte"
    echo "  -h, --help         Afficher cette aide"
    echo ""
    echo "Exemples:"
    echo "  $0                          # Exécuter tous les tests par défaut"
    echo "  $0 -f test_commands.txt     # Exécuter les tests depuis un fichier"
    echo "  $0 --file my_tests.txt      # Même chose avec option longue"
    echo ""
    echo "Format du fichier de tests:"
    echo "  - Une commande par ligne"
    echo "  - Les lignes vides sont ignorées"
    echo "  - Les lignes commençant par # sont des commentaires"
    echo ""
}

# Fonction principale
main() {
    # Traitement des arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            -f|--file)
                CUSTOM_TEST_FILE="$2"
                if [ ! -f "$CUSTOM_TEST_FILE" ]; then
                    echo -e "${RED}Erreur: Le fichier '$CUSTOM_TEST_FILE' n'existe pas${NC}"
                    exit 1
                fi
                shift 2
                ;;
            -h|--help)
                show_help
                exit 0
                ;;
            *)
                echo -e "${RED}Option inconnue: $1${NC}"
                show_help
                exit 1
                ;;
        esac
    done
    
    print_header
    
    # Vérifier que minishell existe
    if [ ! -f "$MINISHELL_PATH" ]; then
        echo -e "${RED}Erreur: $MINISHELL_PATH n'existe pas${NC}"
        echo "Compilez d'abord votre minishell avec 'make'"
        exit 1
    fi
    
    # Si fichier personnalisé spécifié, exécuter seulement ces tests
    if [ -n "$CUSTOM_TEST_FILE" ]; then
        test_custom_from_file
    else
        # Exécuter tous les tests par défaut
        test_builtins
        test_environment_variables
        test_quotes
        test_redirections
        test_pipes
        test_external_commands
        test_error_handling
        test_complex_syntax
        test_whitespace_and_special
    fi
    
    # Résumé final
    echo -e "\n${PURPLE}=====================================${NC}"
    echo -e "${PURPLE}         RÉSUMÉ DES TESTS            ${NC}"
    echo -e "${PURPLE}=====================================${NC}"
    echo -e "Total des tests: ${CYAN}$TOTAL_TESTS${NC}"
    echo -e "Tests réussis:   ${GREEN}$PASSED_TESTS${NC}"
    echo -e "Tests échoués:   ${RED}$FAILED_TESTS${NC}"
    
    if [ $FAILED_TESTS -eq 0 ]; then
        echo -e "\n${GREEN}🎉 Tous les tests sont passés! 🎉${NC}"
        exit 0
    else
        echo -e "\n${YELLOW}⚠️  Certains tests ont échoué ⚠️${NC}"
        exit 1
    fi
}

# Point d'entrée
main "$@"