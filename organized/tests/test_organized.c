/*
** EPITECH PROJECT, 2025
** tests
** File description:
** unit tests for organized
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/organized.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strcmp, same_strings)
{
    cr_assert_eq(my_strcmp("hello", "hello"), 0);
}

Test(my_strcmp, different_strings)
{
    cr_assert_neq(my_strcmp("hello", "world"), 0);
}

Test(my_strcmp, empty_strings)
{
    cr_assert_eq(my_strcmp("", ""), 0);
}

Test(my_strcmp, first_shorter)
{
    cr_assert_neq(my_strcmp("hel", "hello"), 0);
}

Test(my_strcmp, second_shorter)
{
    cr_assert_neq(my_strcmp("hello", "hel"), 0);
}

Test(my_strdup, basic_string)
{
    char *dup = my_strdup("test");
    cr_assert_str_eq(dup, "test");
    free(dup);
}

Test(my_strdup, empty_string)
{
    char *dup = my_strdup("");
    cr_assert_str_eq(dup, "");
    free(dup);
}

Test(my_strdup, long_string)
{
    char *dup = my_strdup("This is a longer test string for coverage");
    cr_assert_str_eq(dup, "This is a longer test string for coverage");
    free(dup);
}

Test(my_getnbr, positive_number)
{
    cr_assert_eq(my_getnbr("42"), 42);
}

Test(my_getnbr, zero)
{
    cr_assert_eq(my_getnbr("0"), 0);
}

Test(my_getnbr, negative_number)
{
    cr_assert_eq(my_getnbr("-42"), -42);
}

Test(my_getnbr, large_number)
{
    cr_assert_eq(my_getnbr("12345"), 12345);
}

Test(my_wordarraylen, basic_array)
{
    char *arr[] = {"one", "two", "three", NULL};
    cr_assert_eq(my_wordarraylen(arr), 3);
}

Test(my_wordarraylen, empty_array)
{
    char *arr[] = {NULL};
    cr_assert_eq(my_wordarraylen(arr), 0);
}

Test(my_wordarraylen, single_element)
{
    char *arr[] = {"single", NULL};
    cr_assert_eq(my_wordarraylen(arr), 1);
}

Test(is_valid_type, valid_wire)
{
    cr_assert_eq(is_valid_type("WIRE"), 0);
}

Test(is_valid_type, valid_device)
{
    cr_assert_eq(is_valid_type("DEVICE"), 0);
}

Test(is_valid_type, invalid_type)
{
    cr_assert_eq(is_valid_type("INVALID"), 1);
}

Test(is_valid_type, valid_sensor)
{
    cr_assert_eq(is_valid_type("SENSOR"), 0);
}

Test(is_valid_type, valid_processor)
{
    cr_assert_eq(is_valid_type("PROCESSOR"), 0);
}

Test(is_valid_type, valid_actuator)
{
    cr_assert_eq(is_valid_type("ACTUATOR"), 0);
}

Test(is_valid_type, empty_string)
{
    cr_assert_eq(is_valid_type(""), 1);
}

Test(push_to_list, add_element)
{
    linked_list_t *list = NULL;
    int data = 42;

    push_to_list(&list, &data);
    cr_assert_not_null(list);
    cr_assert_eq(*((int *)list->data), 42);
    free(list);
}

Test(push_to_list, add_multiple_elements)
{
    linked_list_t *list = NULL;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    push_to_list(&list, &data1);
    push_to_list(&list, &data2);
    push_to_list(&list, &data3);
    cr_assert_not_null(list);
    cr_assert_eq(*((int *)list->data), 3);
    cr_assert_eq(*((int *)list->next->data), 2);
    cr_assert_eq(*((int *)list->next->next->data), 1);
    free(list->next->next);
    free(list->next);
    free(list);
}

Test(my_putstr, basic_string, .init = redirect_all_stdout)
{
    my_putstr("hello");
    cr_assert_stdout_eq_str("hello");
}

Test(my_putstr, null_string, .init = redirect_all_stdout)
{
    my_putstr(NULL);
    cr_assert_stdout_eq_str("");
}

Test(my_putnbr, positive, .init = redirect_all_stdout)
{
    my_putnbr(42);
    cr_assert_stdout_eq_str("42");
}

Test(my_putnbr, zero, .init = redirect_all_stdout)
{
    my_putnbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr, negative, .init = redirect_all_stdout)
{
    my_putnbr(-123);
    cr_assert_stdout_eq_str("-123");
}

Test(my_putnbr, large_number, .init = redirect_all_stdout)
{
    my_putnbr(999999);
    cr_assert_stdout_eq_str("999999");
}

Test(my_putchar, single_char, .init = redirect_all_stdout)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(add, add_single_item, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    char *args[] = {"WIRE", "cable_test", NULL};

    int result = add(&list, args);
    cr_assert_eq(result, 0);
    cr_assert_not_null(list);

    workshop_stock_t *item = (workshop_stock_t *)list->data;
    cr_assert_str_eq(item->type, "WIRE");
    cr_assert_str_eq(item->name, "cable_test");
    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(add, add_invalid_type, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    char *args[] = {"INVALID", "test", NULL};

    int result = add(&list, args);
    cr_assert_eq(result, 84);
}

Test(add, add_no_args)
{
    linked_list_t *list = NULL;
    char *args[] = {NULL};

    int result = add(&list, args);
    cr_assert_eq(result, 84);
}

Test(add, add_missing_name)
{
    linked_list_t *list = NULL;
    char *args[] = {"WIRE", NULL};

    int result = add(&list, args);
    cr_assert_eq(result, 84);
}

Test(add, add_multiple_items, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    char *args[] = {"WIRE", "cable1", "DEVICE", "device1", NULL};

    int result = add(&list, args);
    cr_assert_eq(result, 0);
    cr_assert_not_null(list);
    cr_assert_not_null(list->next);

    workshop_stock_t *item1 = (workshop_stock_t *)list->data;
    workshop_stock_t *item2 = (workshop_stock_t *)list->next->data;

    free(item1->type);
    free(item1->name);
    free(item1);
    free(item2->type);
    free(item2->name);
    free(item2);
    free(list->next);
    free(list);
}

Test(del, del_no_args)
{
    linked_list_t *list = NULL;
    char *args[] = {NULL};

    int result = del(&list, args);
    cr_assert_eq(result, 84);
}

Test(del, del_nonexistent_id)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 0;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    char *args[] = {"999", NULL};
    int result = del(&list, args);
    cr_assert_eq(result, 84);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(del, del_existing_id, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 5;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test_cable");
    push_to_list(&list, item);

    char *args[] = {"5", NULL};
    int result = del(&list, args);
    cr_assert_eq(result, 0);
}

Test(disp, disp_empty_list)
{
    linked_list_t *list = NULL;
    char *args[] = {NULL};

    int result = disp(&list, args);
    cr_assert_eq(result, 84);
}

Test(disp, disp_with_items, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("cable");
    push_to_list(&list, item);

    char *args[] = {NULL};
    int result = disp(&list, args);
    cr_assert_eq(result, 0);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sort, sort_no_args)
{
    linked_list_t *list = NULL;
    char *args[] = {NULL};

    int result = sort(&list, args);
    cr_assert_eq(result, 84);
}

Test(sort, sort_empty_list)
{
    linked_list_t *list = NULL;
    char *args[] = {"NAME", NULL};

    int result = sort(&list, args);
    cr_assert_eq(result, 0);
}

Test(sort, sort_invalid_type)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("cable");
    push_to_list(&list, item);

    char *args[] = {"INVALID_SORT", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 84);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sort, sort_by_name, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("zebra");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("alpha");
    push_to_list(&list, item2);

    char *args[] = {"NAME", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_by_id, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 10;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 1;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    char *args[] = {"ID", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_by_type, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    char *args[] = {"TYPE", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("alpha");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("zebra");
    push_to_list(&list, item2);

    char *args[] = {"NAME", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse_by_type, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("ACTUATOR");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("WIRE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("DEVICE");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    char *args[] = {"TYPE", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse_by_id, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 5;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 15;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 1;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    char *args[] = {"ID", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_three_elements_name, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("charlie");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("alpha");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("bravo");
    push_to_list(&list, item3);

    char *args[] = {"NAME", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_three_elements_type, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("ACTUATOR");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    char *args[] = {"TYPE", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_three_elements_id, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 50;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 10;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 30;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    char *args[] = {"ID", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse_three_name, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("alpha");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("charlie");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("bravo");
    push_to_list(&list, item3);

    char *args[] = {"NAME", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(delete_in_list, delete_single_element)
{
    linked_list_t *list = NULL;
    int data = 42;

    push_to_list(&list, &data);
    delete_in_list(&list, &data);
    cr_assert_null(list);
}

Test(delete_in_list, delete_from_multiple)
{
    linked_list_t *list = NULL;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    push_to_list(&list, &data1);
    push_to_list(&list, &data2);
    push_to_list(&list, &data3);

    delete_in_list(&list, &data2);
    cr_assert_not_null(list);
    cr_assert_eq(*((int *)list->data), 3);

    free(list->next);
    free(list);
}

Test(delete_in_list, delete_last_element)
{
    linked_list_t *list = NULL;
    int data1 = 1;
    int data2 = 2;

    push_to_list(&list, &data1);
    push_to_list(&list, &data2);

    delete_in_list(&list, &data1);
    cr_assert_not_null(list);

    free(list);
}

Test(disp_list, display_list, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    int data1 = 10;
    int data2 = 20;

    push_to_list(&list, &data1);
    push_to_list(&list, &data2);

    disp_list(&list);

    free(list->next);
    free(list);
}

Test(disp_list, display_negative, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;
    int data1 = -42;

    push_to_list(&list, &data1);
    disp_list(&list);

    free(list);
}

Test(sort, sort_single_element, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("single");
    push_to_list(&list, item1);

    char *args[] = {"NAME", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    free(item1->type);
    free(item1->name);
    free(item1);
    free(list);
}

Test(sort, sort_four_elements_name, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("delta");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("alpha");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("charlie");
    push_to_list(&list, item3);

    workshop_stock_t *item4 = malloc(sizeof(workshop_stock_t));
    item4->unique_id = 4;
    item4->type = my_strdup("ACTUATOR");
    item4->name = my_strdup("bravo");
    push_to_list(&list, item4);

    char *args[] = {"NAME", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_four_elements_type, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("ACTUATOR");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    workshop_stock_t *item4 = malloc(sizeof(workshop_stock_t));
    item4->unique_id = 4;
    item4->type = my_strdup("DEVICE");
    item4->name = my_strdup("test4");
    push_to_list(&list, item4);

    char *args[] = {"TYPE", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_four_elements_id, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 100;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 5;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 50;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    workshop_stock_t *item4 = malloc(sizeof(workshop_stock_t));
    item4->unique_id = 25;
    item4->type = my_strdup("ACTUATOR");
    item4->name = my_strdup("test4");
    push_to_list(&list, item4);

    char *args[] = {"ID", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse_four_type, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("ACTUATOR");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("WIRE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("DEVICE");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    workshop_stock_t *item4 = malloc(sizeof(workshop_stock_t));
    item4->unique_id = 4;
    item4->type = my_strdup("SENSOR");
    item4->name = my_strdup("test4");
    push_to_list(&list, item4);

    char *args[] = {"TYPE", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse_four_id, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 10;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 100;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 1;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("test3");
    push_to_list(&list, item3);

    workshop_stock_t *item4 = malloc(sizeof(workshop_stock_t));
    item4->unique_id = 50;
    item4->type = my_strdup("ACTUATOR");
    item4->name = my_strdup("test4");
    push_to_list(&list, item4);

    char *args[] = {"ID", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sort, sort_reverse_four_name, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("alpha");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("delta");
    push_to_list(&list, item2);

    workshop_stock_t *item3 = malloc(sizeof(workshop_stock_t));
    item3->unique_id = 3;
    item3->type = my_strdup("SENSOR");
    item3->name = my_strdup("bravo");
    push_to_list(&list, item3);

    workshop_stock_t *item4 = malloc(sizeof(workshop_stock_t));
    item4->unique_id = 4;
    item4->type = my_strdup("ACTUATOR");
    item4->name = my_strdup("charlie");
    push_to_list(&list, item4);

    char *args[] = {"NAME", "-r", NULL};
    int result = sort(&list, args);
    cr_assert_eq(result, 0);

    linked_list_t *tmp = list;
    while (tmp) {
        workshop_stock_t *it = (workshop_stock_t *)tmp->data;
        free(it->type);
        free(it->name);
        free(it);
        linked_list_t *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

Test(sorted_merge, name_a_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_name(NULL, list);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge, name_b_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_name(list, NULL);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge, type_a_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_type(NULL, list);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge, type_b_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_type(list, NULL);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge, id_a_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_id(NULL, list);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge, id_b_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_id(list, NULL);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge_reverse, name_a_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_name_reverse(NULL, list);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge_reverse, name_b_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_name_reverse(list, NULL);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge_reverse, type_a_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_type_reverse(NULL, list);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge_reverse, type_b_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_type_reverse(list, NULL);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge_reverse, id_a_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_id_reverse(NULL, list);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(sorted_merge_reverse, id_b_null)
{
    linked_list_t *list = NULL;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));
    item->unique_id = 1;
    item->type = my_strdup("WIRE");
    item->name = my_strdup("test");
    push_to_list(&list, item);

    linked_list_t *result = sorted_merge_id_reverse(list, NULL);
    cr_assert_eq(result, list);

    free(item->type);
    free(item->name);
    free(item);
    free(list);
}

Test(del, del_multiple_ids, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("test1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("test2");
    push_to_list(&list, item2);

    char *args[] = {"1", "2", NULL};
    int result = del(&list, args);
    cr_assert_eq(result, 0);
}

Test(disp, disp_multiple_items, .init = redirect_all_stdout)
{
    linked_list_t *list = NULL;

    workshop_stock_t *item1 = malloc(sizeof(workshop_stock_t));
    item1->unique_id = 1;
    item1->type = my_strdup("WIRE");
    item1->name = my_strdup("cable1");
    push_to_list(&list, item1);

    workshop_stock_t *item2 = malloc(sizeof(workshop_stock_t));
    item2->unique_id = 2;
    item2->type = my_strdup("DEVICE");
    item2->name = my_strdup("device1");
    push_to_list(&list, item2);

    char *args[] = {NULL};
    int result = disp(&list, args);
    cr_assert_eq(result, 0);

    free(item1->type);
    free(item1->name);
    free(item1);
    free(item2->type);
    free(item2->name);
    free(item2);
    free(list->next);
    free(list);
}
