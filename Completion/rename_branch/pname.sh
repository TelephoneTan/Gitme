gitme+([[:space:]])rename-branch+([[:space:]])*(?)[^:] | gitme+([[:space:]])rename-branch+([[:space:]]) )
mapfile -t COMPREPLY < <(compgen -W "-help -old-branch: -old-branch:<branch-name> -new-name: -new-name:<branch-name> -force -force: -force:(true\\ |\\ false) -strict-mode -strict-mode: -strict-mode:(on\\ |\\ off)" -- "$cur");;








































































