;; ((c++-mode . ((eval . (setq compile-command
                            ;; (format "clang++ -std=c++20 -DONLINE_JUDGE -I.. %s ../catch_amalgamated.cpp -o solutions && ./solutions"
                                    ;; (file-name-nondirectory (or buffer-file-name ""))))))))

;; auto-compile on save
((c++-mode . ((eval . (add-hook 'after-save-hook
                                `(lambda ()
                                   (setq-local compile-command
                                               ,(format "clang++ -std=c++20 -DONLINE_JUDGE -I.. %s ../catch_amalgamated.cpp -o solutions && ./solutions"
                                                        (file-name-nondirectory (or buffer-file-name ""))))
                                   (compile compile-command))
                                nil t)))))
