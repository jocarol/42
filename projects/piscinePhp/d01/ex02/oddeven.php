#!/usr/bin/php
<?php
while(true)
{
    fwrite(STDOUT, "Entrez un nombre: ");
    $digit = trim(fgets(STDIN));
    if (is_numeric($digit)) {
        if (($digit % 2) == 0)
            fwrite(STDOUT, "Le chiffre $digit est Pair\n");
        else
            fwrite(STDOUT, "Le chiffre $digit est Impair\n");
    } else
        fwrite(STDOUT, "$digit n'est pas un chiffre\n");
}
?>