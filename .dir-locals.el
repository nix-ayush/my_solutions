((c++-mode . ((eval . (setq compile-command
                            (format "clang++ -std=c++20 -DONLINE_JUDGE %s catch_amalgamated.cpp -o solutions && ./solutions"
                                    (file-name-nondirectory (or buffer-file-name ""))))))))
