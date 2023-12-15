function my_prompt_pwd
    # If we are within the DEV_PATH (which we are most of the time) show only the project path
    set prompt_path (string replace $DEV_PATH/ '' $PWD)

    # Replace the full HOME path with ~
    set prompt_path (string replace $HOME '~' $prompt_path)

    echo $prompt_path
end

# Prints the newest file created within the Downloads folder
function downloads_prompt
    if test $PWD = "$HOME/downloads"
        set_color yellow --bold
        echo -n ' ('

        set_color cyan --bold
        echo -n (ls -1 --sort newest | tail -1)

        set_color yellow --bold
        echo -n ')'

        set_color normal
    end
end

function fish_prompt
    set -g __fish_git_prompt_showcolorhints 1
    set -g __fish_git_prompt_showdirtystate 1
    set -g __fish_git_prompt_showstashstate 1
    set -g __fish_git_prompt_showuntrackedfiles 1
    set -g __fish_git_prompt_showupstream informative

    set -g __fish_git_prompt_color_prefix blue --bold
    set -g __fish_git_prompt_color_suffix blue --bold
    set -g __fish_git_prompt_color_branch cyan --bold
    set -g __fish_git_prompt_color_untrackedfiles c540ed --bold
    set -g __fish_git_prompt_color_dirtystate ffc200 --bold
    set -g __fish_git_prompt_color_stagedstate 31e02f --bold
    set -g __fish_git_prompt_color_stashstate cyan
    set -g __fish_git_prompt_color_upstream red

    set -g __fish_git_prompt_char_stagedstate '•' # U+2022
    set -g __fish_git_prompt_char_dirtystate '•' # U+2022
    set -g __fish_git_prompt_char_untrackedfiles '•' # U+2022
    set -g __fish_git_prompt_char_invalidstate '✘' # U+2718
    set -g __fish_git_prompt_char_conflictedstate '✘' # U+2718
    set -g __fish_git_prompt_char_stashstate '#'
    set -g __fish_git_prompt_char_cleanstate '✔' # U+2714
    set -g __fish_git_prompt_char_upstream_behind ' 🠇' # U+1F807
    set -g __fish_git_prompt_char_upstream_ahead ' 🠅' # U+1F805
    set -g __fish_git_prompt_char_upstream_diverged '⮃' # U+2B83

    printf '\n'

    set_color blue --bold
    printf '%s' (my_prompt_pwd)
    set_color normal

    printf '%s' (downloads_prompt)

    printf '%s' (__fish_git_prompt)

    # printf '\n➜ '
    printf '\n⮞ ' # U+2B9E

    set_color normal
end
