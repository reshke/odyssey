#ifndef MM_SLEEP_LOCK_H
#define MM_SLEEP_LOCK_H

/*
 * machinarium.
 *
 * cooperative multitasking engine.
*/

typedef pthread_spinlock_t mm_sleeplock_t;

#if defined(__x86_64__) || defined(__i386) || defined(_X86_)
#  define MM_SLEEPLOCK_BACKOFF __asm__ ("pause")
#else
#  define MM_SLEEPLOCK_BACKOFF
#endif

static inline void
mm_sleeplock_init(mm_sleeplock_t *lock)
{
	pthread_spin_init(lock, 0);
}

static inline void
mm_sleeplock_lock(mm_sleeplock_t *lock)
{
	pthread_spin_lock(lock);
}

static inline void
mm_sleeplock_unlock(mm_sleeplock_t *lock)
{
	pthread_spin_unlock(lock);
}

#endif /* MM_SLEEP_LOCK_H */
