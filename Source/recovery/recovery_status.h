#ifndef RECOVERY_STATUS_H
#define RECOVERY_STATUS_H

enum class RecoveryAction {
    NONE,
    WIPE_CACHE,
    FACTORY_RESET,
    APPLY_UPDATE,
    RESTORE_BACKUP,
    MOUNT_PARTITIONS,
    CHECK_SYSTEM
};

enum class RecoveryResult {
    SUCCESS,
    FAILURE,
    SKIPPED
};

#endif
