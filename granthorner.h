#ifndef GRANT_HORNER_H
#define GRANT_HORNER_H

#define GRANT_HORNER_LIST_COUNT 10
#define BOOK_MAX_NAME_LEN 64
#define BOOK_MAX_ABBR_LEN 8

typedef unsigned short int gh_small_uint;
typedef unsigned long int gh_big_uint;

struct book_s {
	char name[BOOK_MAX_NAME_LEN];	/* name of book */
	char abbr[BOOK_MAX_ABBR_LEN];	/* osisID (book abbreviation) */
	gh_small_uint chapters;		/* number of chapters in book */
};

struct book_list_s {
	struct book_s *books;		/* books in a Grant Horner list */
	gh_small_uint count;		/* number of books in the list */
};

/* represents position in a list, calculated for a particular day */
struct book_list_position_s {
	struct book_s *book;		/* the book */
	gh_small_uint chapter;		/* the chapter */
};

/* represents the lists defined by Grant Horner */
struct grant_horner_s {
	struct book_list_s lists[GRANT_HORNER_LIST_COUNT];
};

/* memory management */
struct grant_horner_s *grant_horner_alloc(void);
void grant_horner_free(struct grant_horner_s *gh);

/* number crunching to return the struct book_list_position_s */
struct book_list_position_s grant_horner_book_list_position_by_day(struct book_list_s *bl, gh_big_uint day);

#endif
